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

#endif
