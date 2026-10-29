# Renders an OBJ (tools/assets/obdbpf s3d) in Blender, unlit (the textures carry their own lighting), through an
# orthographic camera looking down at the game's angle, to a PNG with transparency.
#   blender -b --factory-startup -P tools/assets/render_obj.py -- <model.obj> <out.png> [yaw degrees] [pitch degrees] [size]
# Blender's Python scripting, allowed for Blender work only (user, 2026-10-29).
import math
import sys

import bpy
from mathutils import Vector

args = sys.argv[sys.argv.index("--") + 1:]
obj_path, out_path = args[0], args[1]
yaw = float(args[2]) if len(args) > 2 else 22.5
pitch = float(args[3]) if len(args) > 3 else 45.0
size = int(args[4]) if len(args) > 4 else 512

bpy.ops.wm.read_factory_settings(use_empty=True)
bpy.ops.wm.obj_import(filepath=obj_path)
objs = [o for o in bpy.context.scene.objects if o.type == "MESH"]

# unlit: each material's texture straight to the output, its alpha as transparency
for mat in bpy.data.materials:
    mat.use_nodes = True
    nt = mat.node_tree
    # the image the importer found, then a fresh tree (a node handle dies when another node is removed)
    image = next((n.image for n in nt.nodes if n.type == "TEX_IMAGE"), None)
    nt.nodes.clear()
    tex = None
    if image:
        tex = nt.nodes.new("ShaderNodeTexImage")
        tex.image = image
    out = nt.nodes.new("ShaderNodeOutputMaterial")
    emit = nt.nodes.new("ShaderNodeEmission")
    mix = nt.nodes.new("ShaderNodeMixShader")
    clear = nt.nodes.new("ShaderNodeBsdfTransparent")
    if tex:
        tex.interpolation = "Closest"
        nt.links.new(tex.outputs["Color"], emit.inputs["Color"])
        nt.links.new(tex.outputs["Alpha"], mix.inputs["Fac"])
    nt.links.new(clear.outputs[0], mix.inputs[1])
    nt.links.new(emit.outputs[0], mix.inputs[2])
    nt.links.new(mix.outputs[0], out.inputs["Surface"])

# frame the model: its bounding box from every mesh
pts = [o.matrix_world @ Vector(c) for o in objs for c in o.bound_box]
lo = Vector((min(p.x for p in pts), min(p.y for p in pts), min(p.z for p in pts)))
hi = Vector((max(p.x for p in pts), max(p.y for p in pts), max(p.z for p in pts)))
centre = (lo + hi) / 2
radius = (hi - lo).length / 2

cam_data = bpy.data.cameras.new("cam")
cam_data.type = "ORTHO"
cam_data.ortho_scale = radius * 2.2
cam = bpy.data.objects.new("cam", cam_data)
bpy.context.scene.collection.objects.link(cam)
d = Vector((math.cos(math.radians(pitch)) * math.sin(math.radians(yaw)),
            -math.cos(math.radians(pitch)) * math.cos(math.radians(yaw)),
            math.sin(math.radians(pitch))))
cam.location = centre + d * radius * 4
cam.rotation_euler = (-d).to_track_quat("-Z", "Y").to_euler()
bpy.context.scene.camera = cam

scene = bpy.context.scene
scene.render.engine = "BLENDER_EEVEE_NEXT" if "BLENDER_EEVEE_NEXT" in {e.identifier for e in bpy.types.RenderSettings.bl_rna.properties["engine"].enum_items} else "BLENDER_EEVEE"
scene.render.film_transparent = True
scene.render.resolution_x = scene.render.resolution_y = size
scene.view_settings.view_transform = "Standard"
scene.render.filepath = out_path
bpy.ops.render.render(write_still=True)
print("rendered", out_path)
