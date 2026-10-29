// The OpenGL 1.1 functions and constants the OpenGL graphics driver uses, declared here rather than taken from a
// system header: the 2003 compiler needs them imported from opengl32.dll with __stdcall (as the original called
// them), other compilers get plain declarations for the platform's own GL library.
#ifndef OB_ENGINE_GL_H
#define OB_ENGINE_GL_H

typedef unsigned int GLenum;
typedef unsigned int GLbitfield;
typedef unsigned int GLuint;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLboolean;
typedef unsigned char GLubyte;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;

#ifdef _MSC_VER
#define OB_GLAPI extern "C" __declspec(dllimport)
#define OB_GLCALL __stdcall
#else
#define OB_GLAPI extern "C"
#define OB_GLCALL
#endif

// Enable states, tests and the rest, as the driver's translation tables hold them.
#define GL_NEVER 0x0200
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_FLAT 0x1D00
#define GL_SMOOTH 0x1D01
#define GL_AMBIENT 0x1200
#define GL_DIFFUSE 0x1201
#define GL_SPECULAR 0x1202
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_DOUBLE 0x140A
#define GL_TEXTURE 0x1702
#define GL_CONSTANT_ARB 0x8576
#define GL_PRIMARY_COLOR_ARB 0x8577
#define GL_PREVIOUS_ARB 0x8578
#define GL_SOURCE0_RGB_ARB 0x8580
#define GL_SOURCE1_RGB_ARB 0x8581
#define GL_SOURCE2_RGB_ARB 0x8582
#define GL_SOURCE3_RGB_NV 0x8583
#define GL_SOURCE0_ALPHA_ARB 0x8588
#define GL_SOURCE1_ALPHA_ARB 0x8589
#define GL_SOURCE2_ALPHA_ARB 0x858A
#define GL_SOURCE3_ALPHA_NV 0x858B
#define GL_OPERAND0_RGB_ARB 0x8590
#define GL_OPERAND1_RGB_ARB 0x8591
#define GL_OPERAND2_RGB_ARB 0x8592
#define GL_OPERAND3_RGB_NV 0x8593
#define GL_OPERAND0_ALPHA_ARB 0x8598
#define GL_OPERAND1_ALPHA_ARB 0x8599
#define GL_OPERAND2_ALPHA_ARB 0x859A
#define GL_OPERAND3_ALPHA_NV 0x859B
#define GL_RGB_SCALE_ARB 0x8573
#define GL_ALPHA_SCALE 0x0D1C
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_STRIP 0x0003
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_QUADS 0x0007
#define GL_QUAD_STRIP 0x0008
#define GL_KEEP 0x1E00
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
#define GL_INVERT 0x150A
#define GL_VIEWPORT 0x0BA2
#define GL_COMBINE_RGB_ARB 0x8571
#define GL_COMBINE_ALPHA_ARB 0x8572
#define GL_ADD 0x0104
#define GL_ADD_SIGNED_ARB 0x8574
#define GL_INTERPOLATE_ARB 0x8575
#define GL_DOT3_RGB_EXT 0x8740
#define GL_LIGHT0 0x4000
#define GL_LIGHT_MODEL_AMBIENT 0x0B53
#define GL_INVALID_VALUE 0x0501
#define GL_REPLACE 0x1E01
#define GL_MODULATE 0x2100
#define GL_DECAL 0x2101
#define GL_COMBINE_ARB 0x8570
#define GL_COMBINE4_NV 0x8503
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_NEAREST 0x2600
#define GL_CLAMP 0x2900
#define GL_REPEAT 0x2901
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_SCISSOR_TEST 0x0C11
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE0_ARB 0x84C0
#define GL_ZERO 0
#define GL_ONE 1
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_LIGHTING 0x0B50
#define GL_TEXTURE_ENV 0x2300
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_TEXTURE_ENV_COLOR 0x2201
#define GL_EXP 0x0800
#define GL_EXP2 0x0801
#define GL_LINEAR 0x2601
#define GL_FOG_COORDINATE_EXT 0x8451
#define GL_MODELVIEW 0x1700
#define GL_PROJECTION 0x1701
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_FOG_DENSITY 0x0B62
#define GL_FOG_START 0x0B63
#define GL_FOG_END 0x0B64
#define GL_FOG_MODE 0x0B65
#define GL_FOG_COLOR 0x0B66
#define GL_FOG_COORDINATE_SOURCE_EXT 0x8450
#define GL_ALPHA_TEST 0x0BC0
#define GL_DEPTH_TEST 0x0B71
#define GL_STENCIL_TEST 0x0B90
#define GL_CULL_FACE 0x0B44
#define GL_BLEND 0x0BE2
#define GL_TEXTURE_2D 0x0DE1
#define GL_FOG 0x0B60
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_BUFFER_BIT 0x00000400

OB_GLAPI void OB_GLCALL glAlphaFunc(GLenum func, GLclampf ref);
OB_GLAPI GLboolean OB_GLCALL glAreTexturesResident(GLsizei n, const GLuint* textures, GLboolean* residences);
OB_GLAPI void OB_GLCALL glBindTexture(GLenum target, GLuint texture);
OB_GLAPI void OB_GLCALL glBlendFunc(GLenum sfactor, GLenum dfactor);
OB_GLAPI void OB_GLCALL glClear(GLbitfield mask);
OB_GLAPI void OB_GLCALL glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
OB_GLAPI void OB_GLCALL glClearDepth(GLclampd depth);
OB_GLAPI void OB_GLCALL glClearStencil(GLint s);
OB_GLAPI void OB_GLCALL glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
OB_GLAPI void OB_GLCALL glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
OB_GLAPI void OB_GLCALL glColorMaterial(GLenum face, GLenum mode);
OB_GLAPI void OB_GLCALL glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
OB_GLAPI void OB_GLCALL glDeleteTextures(GLsizei n, const GLuint* textures);
OB_GLAPI void OB_GLCALL glDepthFunc(GLenum func);
OB_GLAPI void OB_GLCALL glDepthMask(GLboolean flag);
OB_GLAPI void OB_GLCALL glDisable(GLenum cap);
OB_GLAPI void OB_GLCALL glDisableClientState(GLenum array);
OB_GLAPI void OB_GLCALL glDrawArrays(GLenum mode, GLint first, GLsizei count);
OB_GLAPI void OB_GLCALL glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
OB_GLAPI void OB_GLCALL glEnable(GLenum cap);
OB_GLAPI void OB_GLCALL glEnableClientState(GLenum array);
OB_GLAPI void OB_GLCALL glFlush();
OB_GLAPI void OB_GLCALL glFogfv(GLenum pname, const GLfloat* params);
OB_GLAPI void OB_GLCALL glFogi(GLenum pname, GLint param);
OB_GLAPI void OB_GLCALL glGenTextures(GLsizei n, GLuint* textures);
OB_GLAPI void OB_GLCALL glGetBooleanv(GLenum pname, GLboolean* params);
OB_GLAPI GLenum OB_GLCALL glGetError();
OB_GLAPI void OB_GLCALL glGetFloatv(GLenum pname, GLfloat* params);
OB_GLAPI void OB_GLCALL glGetIntegerv(GLenum pname, GLint* params);
OB_GLAPI const GLubyte* OB_GLCALL glGetString(GLenum name);
OB_GLAPI void OB_GLCALL glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint* params);
OB_GLAPI GLboolean OB_GLCALL glIsEnabled(GLenum cap);
OB_GLAPI GLboolean OB_GLCALL glIsTexture(GLuint texture);
OB_GLAPI void OB_GLCALL glLightfv(GLenum light, GLenum pname, const GLfloat* params);
OB_GLAPI void OB_GLCALL glLightModelfv(GLenum pname, const GLfloat* params);
OB_GLAPI void OB_GLCALL glLoadIdentity();
OB_GLAPI void OB_GLCALL glLoadMatrixf(const GLfloat* m);
OB_GLAPI void OB_GLCALL glMaterialfv(GLenum face, GLenum pname, const GLfloat* params);
OB_GLAPI void OB_GLCALL glMatrixMode(GLenum mode);
OB_GLAPI void OB_GLCALL glNormalPointer(GLenum type, GLsizei stride, const GLvoid* pointer);
OB_GLAPI void OB_GLCALL glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear,
                                GLdouble zFar);
OB_GLAPI void OB_GLCALL glPixelStorei(GLenum pname, GLint param);
OB_GLAPI void OB_GLCALL glPolygonOffset(GLfloat factor, GLfloat units);
OB_GLAPI void OB_GLCALL glPrioritizeTextures(GLsizei n, const GLuint* textures, const GLclampf* priorities);
OB_GLAPI void OB_GLCALL glReadBuffer(GLenum mode);
OB_GLAPI void OB_GLCALL glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type,
                                     GLvoid* pixels);
OB_GLAPI void OB_GLCALL glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
OB_GLAPI void OB_GLCALL glShadeModel(GLenum mode);
OB_GLAPI void OB_GLCALL glStencilFunc(GLenum func, GLint ref, GLuint mask);
OB_GLAPI void OB_GLCALL glStencilMask(GLuint mask);
OB_GLAPI void OB_GLCALL glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
OB_GLAPI void OB_GLCALL glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
OB_GLAPI void OB_GLCALL glTexEnvfv(GLenum target, GLenum pname, const GLfloat* params);
OB_GLAPI void OB_GLCALL glTexEnvi(GLenum target, GLenum pname, GLint param);
OB_GLAPI void OB_GLCALL glTexGenfv(GLenum coord, GLenum pname, const GLfloat* params);
OB_GLAPI void OB_GLCALL glTexGeni(GLenum coord, GLenum pname, GLint param);
OB_GLAPI void OB_GLCALL glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height,
                                     GLint border, GLenum format, GLenum type, const GLvoid* pixels);
OB_GLAPI void OB_GLCALL glTexParameteri(GLenum target, GLenum pname, GLint param);
OB_GLAPI void OB_GLCALL glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width,
                                        GLsizei height, GLenum format, GLenum type, const GLvoid* pixels);
OB_GLAPI void OB_GLCALL glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid* pointer);
OB_GLAPI void OB_GLCALL glViewport(GLint x, GLint y, GLsizei width, GLsizei height);


// The Windows side: the current device context and swapping its buffers (gdi32).
OB_GLAPI void* OB_GLCALL wglGetCurrentDC();
OB_GLAPI int OB_GLCALL SwapBuffers(void* dc);

#endif
