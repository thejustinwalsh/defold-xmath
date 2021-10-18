#define LIB_NAME "xmath"
#define MODULE_NAME "xmath"
#define DLIB_LOG_DOMAIN "xMath"

#include <dmsdk/sdk.h>

static int xMath_add(lua_State* L)
{
    if (dmScript::IsVector3(L, 1))
    {
        Vectormath::Aos::Vector3 *out = dmScript::CheckVector3(L, 1);
        Vectormath::Aos::Vector3 *lhs = dmScript::CheckVector3(L, 2);
        Vectormath::Aos::Vector3 *rhs = dmScript::CheckVector3(L, 3);
        *out = *lhs + *rhs;
    }
    else if (dmScript::IsVector4(L, 1))
    {
        Vectormath::Aos::Vector4 *out = dmScript::CheckVector4(L, 1);
        Vectormath::Aos::Vector4 *lhs = dmScript::CheckVector4(L, 2);
        Vectormath::Aos::Vector4 *rhs = dmScript::CheckVector4(L, 3);
        *out = *lhs + *rhs;
    }

    return 0;
}

static int xMath_sub(lua_State* L)
{
    if (dmScript::IsVector3(L, 1))
    {
        Vectormath::Aos::Vector3 *out = dmScript::CheckVector3(L, 1);
        Vectormath::Aos::Vector3 *lhs = dmScript::CheckVector3(L, 2);
        Vectormath::Aos::Vector3 *rhs = dmScript::CheckVector3(L, 3);
        *out = *lhs - *rhs;
    }
    else if (dmScript::IsVector4(L, 1))
    {
        Vectormath::Aos::Vector4 *out = dmScript::CheckVector4(L, 1);
        Vectormath::Aos::Vector4 *lhs = dmScript::CheckVector4(L, 2);
        Vectormath::Aos::Vector4 *rhs = dmScript::CheckVector4(L, 3);
        *out = *lhs - *rhs;
    }

    return 0;
}

static int xMath_mul(lua_State* L)
{
    if (dmScript::IsVector3(L, 1))
    {
        Vectormath::Aos::Vector3 *out = dmScript::CheckVector3(L, 1);
        Vectormath::Aos::Vector3 *lhs = dmScript::CheckVector3(L, 2);
        float rhs = (float) luaL_checknumber(L, 3);
        *out = *lhs * rhs;
    }
    else if (dmScript::IsVector4(L, 1))
    {
        Vectormath::Aos::Vector4 *out = dmScript::CheckVector4(L, 1);
        Vectormath::Aos::Vector4 *lhs = dmScript::CheckVector4(L, 2);
        float rhs = (float) luaL_checknumber(L, 3);
        *out = *lhs * rhs;
    }

    return 0;
}

static int xMath_div(lua_State* L)
{
    if (dmScript::IsVector3(L, 1))
    {
        Vectormath::Aos::Vector3 *out = dmScript::CheckVector3(L, 1);
        Vectormath::Aos::Vector3 *lhs = dmScript::CheckVector3(L, 2);
        float rhs = (float) luaL_checknumber(L, 3);
        *out = *lhs / rhs;
    }
    else if (dmScript::IsVector4(L, 1))
    {
        Vectormath::Aos::Vector4 *out = dmScript::CheckVector4(L, 1);
        Vectormath::Aos::Vector4 *lhs = dmScript::CheckVector4(L, 2);
        float rhs = (float) luaL_checknumber(L, 3);
        *out = *lhs / rhs;
    }

    return 0;
}

static int xMath_normalize(lua_State* L)
{
    if (dmScript::IsVector3(L, 1))
    {
        Vectormath::Aos::Vector3 *out = dmScript::CheckVector3(L, 1);
        Vectormath::Aos::Vector3 *a = dmScript::CheckVector3(L, 2);
        *out = Vectormath::Aos::normalize(*a);
    }
    else if (dmScript::IsVector4(L, 1))
    {
        Vectormath::Aos::Vector4 *out = dmScript::CheckVector4(L, 1);
        Vectormath::Aos::Vector4 *a = dmScript::CheckVector4(L, 2);
        *out = Vectormath::Aos::normalize(*a);
    }

    return 0;
}

static int xMath_cross(lua_State* L)
{
    if (dmScript::IsVector3(L, 1))
    {
        Vectormath::Aos::Vector3 *out = dmScript::CheckVector3(L, 1);
        Vectormath::Aos::Vector3 *lhs = dmScript::CheckVector3(L, 2);
        Vectormath::Aos::Vector3 *rhs = dmScript::CheckVector3(L, 3);
        *out = Vectormath::Aos::cross(*lhs, *rhs);
    }
    
    return 0;
}

static int xMath_rotate(lua_State* L)
{
    if (dmScript::IsVector3(L, 1))
    {
        Vectormath::Aos::Vector3 *out = dmScript::CheckVector3(L, 1);
        Vectormath::Aos::Quat *lhs = dmScript::CheckQuat(L, 2);
        Vectormath::Aos::Vector3 *rhs = dmScript::CheckVector3(L, 3);
        *out = Vectormath::Aos::rotate(*lhs, *rhs);
    }

    return 0;
}

static const luaL_reg xMathModule_methods[] =
{
    {"add", xMath_add},
    {"sub", xMath_sub},
    {"mul", xMath_mul},
    {"div", xMath_div},
    {"normalize", xMath_normalize},
    {"cross", xMath_cross},
    {"rotate", xMath_rotate},
    {0, 0}
};

static void xMathLuaInit(lua_State* L)
{
    int top = lua_gettop(L);

    luaL_register(L, MODULE_NAME, xMathModule_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result xMathAppInitialize(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result xMathInitialize(dmExtension::Params* params)
{
    xMathLuaInit(params->m_L);
    dmLogInfo("Registered %s Extension\n", MODULE_NAME);
    return dmExtension::RESULT_OK;
}

dmExtension::Result xMathAppFinalize(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result xMathFinalize(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

// Defold SDK uses a macro for setting up extension entry points:
// It must match the name field in the `ext.manifest`
DM_DECLARE_EXTENSION(xMath, LIB_NAME, xMathAppInitialize, xMathAppFinalize, xMathInitialize, 0, 0, xMathFinalize)
