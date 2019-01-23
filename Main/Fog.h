#pragma once

struct RGBAStruct
{
	float r, g, b, a;
};  

RGBAStruct FogMapColor(int Map);

void FogOn();
void FogOff();

void APIENTRY glEnable_Hooked(GLenum cap); 
typedef void (APIENTRY *ptr_glEnable)(GLenum);
void APIENTRY glClearColor_Hooked(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef void (APIENTRY *ptr_glClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);