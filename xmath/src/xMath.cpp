#define LIB_NAME "xmath"
#define MODULE_NAME "xmath"
#define DLIB_LOG_DOMAIN "xMath"

#include <dmsdk/sdk.h>

//* Arithmetic
//* ----------------------------------------------------------------------------

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

//* Vector
//* ----------------------------------------------------------------------------

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

static int xMath_mul_per_elem(lua_State* L)
{
    if (dmScript::IsVector3(L, 1))
    {
        Vectormath::Aos::Vector3 *out = dmScript::CheckVector3(L, 1);
        Vectormath::Aos::Vector3 *lhs = dmScript::CheckVector3(L, 2);
        Vectormath::Aos::Vector3 *rhs = dmScript::CheckVector3(L, 3);
        *out = Vectormath::Aos::mulPerElem(*lhs, *rhs);
    }
    else if (dmScript::IsVector4(L, 1))
    {
        Vectormath::Aos::Vector4 *out = dmScript::CheckVector4(L, 1);
        Vectormath::Aos::Vector4 *lhs = dmScript::CheckVector4(L, 2);
        Vectormath::Aos::Vector4 *rhs = dmScript::CheckVector4(L, 3);
        *out = Vectormath::Aos::mulPerElem(*lhs, *rhs);
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

static int xMath_vector(lua_State* L)
{
    if (dmScript::IsVector3(L, 1))
    {
        Vectormath::Aos::Vector3 *out = dmScript::CheckVector3(L, 1);
        *out = Vectormath::Aos::Vector3(0, 0, 0);
    }
    else if (dmScript::IsVector4(L, 1))
    {
        Vectormath::Aos::Vector4 *out = dmScript::CheckVector4(L, 1);
        *out = Vectormath::Aos::Vector4(0, 0, 0, 1);
    }

    return 0;
}

//* Quat
//* ----------------------------------------------------------------------------

static int xMath_conj(lua_State* L)
{
    if (dmScript::IsQuat(L, 1))
    {
        Vectormath::Aos::Quat *out = dmScript::CheckQuat(L, 1);
        Vectormath::Aos::Quat *a = dmScript::CheckQuat(L, 2);
        *out = Vectormath::Aos::conj(*a);
    }

    return 0;
}

static int xMath_quat_axis_angle(lua_State* L)
{
    if (dmScript::IsQuat(L, 1))
    {
        Vectormath::Aos::Quat *out = dmScript::CheckQuat(L, 1);
        Vectormath::Aos::Vector3 *axis = dmScript::CheckVector3(L, 2);
        float angle = (float) luaL_checknumber(L, 3);
        *out = Vectormath::Aos::Quat(*axis, angle);
    }

    return 0;
}

static int xMath_quat_basis(lua_State* L)
{
    if (dmScript::IsQuat(L, 1))
    {
        Vectormath::Aos::Quat *out = dmScript::CheckQuat(L, 1);
        Vectormath::Aos::Vector3 *x = dmScript::CheckVector3(L, 2);
        Vectormath::Aos::Vector3 *y = dmScript::CheckVector3(L, 3);
        Vectormath::Aos::Vector3 *z = dmScript::CheckVector3(L, 4);
        Vectormath::Aos::Matrix3 m;
        m.setCol0(*x);
        m.setCol1(*y);
        m.setCol2(*z);
        *out = Vectormath::Aos::Quat(m);
    }

    return 0;
}

static int xMath_quat_from_to(lua_State* L)
{
    if (dmScript::IsQuat(L, 1))
    {
        Vectormath::Aos::Quat *out = dmScript::CheckQuat(L, 1);
        Vectormath::Aos::Vector3 *from = dmScript::CheckVector3(L, 2);
        Vectormath::Aos::Vector3 *to = dmScript::CheckVector3(L, 3);
        *out = Vectormath::Aos::Quat::rotation(*from, *to);
    }
    
    return 0;
}

static int xMath_quat_rotation_x(lua_State* L)
{
    if (dmScript::IsQuat(L, 1))
    {
        Vectormath::Aos::Quat *out = dmScript::CheckQuat(L, 1);
        float angle = (float) luaL_checknumber(L, 2);
        *out = Vectormath::Aos::Quat::rotationX(angle);
    }

    return 0;
}

static int xMath_quat_rotation_y(lua_State* L)
{
    if (dmScript::IsQuat(L, 1))
    {
        Vectormath::Aos::Quat *out = dmScript::CheckQuat(L, 1);
        float angle = (float) luaL_checknumber(L, 2);
        *out = Vectormath::Aos::Quat::rotationY(angle);
    }

    return 0;
}

static int xMath_quat_rotation_z(lua_State* L)
{
    if (dmScript::IsQuat(L, 1))
    {
        Vectormath::Aos::Quat *out = dmScript::CheckQuat(L, 1);
        float angle = (float) luaL_checknumber(L, 2);
        *out = Vectormath::Aos::Quat::rotationZ(angle);
    }

    return 0;
}

static int xMath_quat(lua_State* L)
{
    if (dmScript::IsQuat(L, 1))
    {
        Vectormath::Aos::Quat *out = dmScript::CheckQuat(L, 1);
        *out = Vectormath::Aos::Quat::identity();
    }

    return 0;
}

//* Vector + Quat
//* ----------------------------------------------------------------------------

static int xMath_lerp(lua_State* L)
{
    if (lua_isnumber(L, 1))
    {
        float out = luaL_checknumber(L, 1);
        float t = (float) luaL_checknumber(L, 2);
        float lhs = (float) luaL_checknumber(L, 3);
        float rhs = (float) luaL_checknumber(L, 4);
        out = (lhs + ((rhs - lhs) * t));
    }
    else if (dmScript::IsVector3(L, 1))
    {
        Vectormath::Aos::Vector3 *out = dmScript::CheckVector3(L, 1);
        float t = (float) luaL_checknumber(L, 2);
        Vectormath::Aos::Vector3 *lhs = dmScript::CheckVector3(L, 3);
        Vectormath::Aos::Vector3 *rhs = dmScript::CheckVector3(L, 4);
        *out = Vectormath::Aos::lerp(t, *lhs, *rhs);
    }
    else if (dmScript::IsVector4(L, 1))
    {
        Vectormath::Aos::Vector4 *out = dmScript::CheckVector4(L, 1);
        float t = (float) luaL_checknumber(L, 2);
        Vectormath::Aos::Vector4 *lhs = dmScript::CheckVector4(L, 3);
        Vectormath::Aos::Vector4 *rhs = dmScript::CheckVector4(L, 4);
        *out = Vectormath::Aos::lerp(t, *lhs, *rhs);
    }
    else if (dmScript::IsQuat(L, 1))
    {
        Vectormath::Aos::Quat *out = dmScript::CheckQuat(L, 1);
        float t = (float) luaL_checknumber(L, 2);
        Vectormath::Aos::Quat *lhs = dmScript::CheckQuat(L, 3);
        Vectormath::Aos::Quat *rhs = dmScript::CheckQuat(L, 4);
        *out = Vectormath::Aos::slerp(t, *lhs, *rhs);
    }
    
    return 0;
}

static int xMath_slerp(lua_State* L)
{
    if (dmScript::IsVector3(L, 1))
    {
        Vectormath::Aos::Vector3 *out = dmScript::CheckVector3(L, 1);
        float t = (float) luaL_checknumber(L, 2);
        Vectormath::Aos::Vector3 *lhs = dmScript::CheckVector3(L, 3);
        Vectormath::Aos::Vector3 *rhs = dmScript::CheckVector3(L, 4);
        *out = Vectormath::Aos::slerp(t, *lhs, *rhs);
    }
    else if (dmScript::IsVector4(L, 1))
    {
        Vectormath::Aos::Vector4 *out = dmScript::CheckVector4(L, 1);
        float t = (float) luaL_checknumber(L, 2);
        Vectormath::Aos::Vector4 *lhs = dmScript::CheckVector4(L, 3);
        Vectormath::Aos::Vector4 *rhs = dmScript::CheckVector4(L, 4);
        *out = Vectormath::Aos::slerp(t, *lhs, *rhs);
    }
    else if (dmScript::IsQuat(L, 1))
    {
        Vectormath::Aos::Quat *out = dmScript::CheckQuat(L, 1);
        float t = (float) luaL_checknumber(L, 2);
        Vectormath::Aos::Quat *lhs = dmScript::CheckQuat(L, 3);
        Vectormath::Aos::Quat *rhs = dmScript::CheckQuat(L, 4);
        *out = Vectormath::Aos::slerp(t, *lhs, *rhs);
    }
    
    return 0;
}

//* Matrix
//* ----------------------------------------------------------------------------

static int xMath_matrix(lua_State* L)
{
    if (lua_gettop(L) == 0 && dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        *out = Vectormath::Aos::Matrix4::identity();
    }
    else if (lua_gettop(L) == 1 && dmScript::IsMatrix4(L, 1) && dmScript::IsMatrix4(L, 2))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        Vectormath::Aos::Matrix4 *in = dmScript::CheckMatrix4(L, 1);
        *out = *in;
    }
    
    return 0;
}

static int xMath_matrix_axis_angle(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        Vectormath::Aos::Vector3 *axis = dmScript::CheckVector3(L, 2);
        float angle = (float) luaL_checknumber(L, 3);
        *out = Vectormath::Aos::Matrix4::rotation(angle, *axis);
    }

    return 0;
}

static int xMath_matrix_from_quat(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        Vectormath::Aos::Quat *quat = dmScript::CheckQuat(L, 2);
        *out = Vectormath::Aos::Matrix4::rotation(*quat);
    }

    return 0;
}

static int xMath_matrix_frustum(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        float left = (float) luaL_checknumber(L, 2);
        float right = (float) luaL_checknumber(L, 3);
        float bottom = (float) luaL_checknumber(L, 4);
        float top = (float) luaL_checknumber(L, 5);
        float near_z = (float) luaL_checknumber(L, 6);
        if(near_z == 0.0f) near_z = 0.00001f;
        float far_z = (float) luaL_checknumber(L, 7);
        *out = Vectormath::Aos::Matrix4::frustum(left, right, bottom, top, near_z, far_z);
    }

    return 0;
}

static int xMath_matrix_inv(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        Vectormath::Aos::Matrix4 *in = dmScript::CheckMatrix4(L, 2);
        *out = Vectormath::Aos::inverse(*in);
    }
    return 0;
}

static int xMath_matrix_look_at(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        Vectormath::Aos::Point3 eye = Vectormath::Aos::Point3(*dmScript::CheckVector3(L, 2));
        Vectormath::Aos::Point3 target = Vectormath::Aos::Point3(*dmScript::CheckVector3(L, 3));
        Vectormath::Aos::Vector3 up = *dmScript::CheckVector3(L, 4);
        *out = Vectormath::Aos::Matrix4::lookAt(eye, target, up);
    }

    return 0;
}

static int xMath_matrix_orthographic(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        float left = (float) luaL_checknumber(L, 2);
        float right = (float) luaL_checknumber(L, 3);
        float bottom = (float) luaL_checknumber(L, 4);
        float top = (float) luaL_checknumber(L, 5);
        float near_z = (float) luaL_checknumber(L, 6);
        float far_z = (float) luaL_checknumber(L, 7);
        *out = Vectormath::Aos::Matrix4::orthographic(left, right, bottom, top, near_z, far_z);
    }

    return 0;
}

static int xMath_matrix_ortho_inv(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        Vectormath::Aos::Matrix4 *in = dmScript::CheckMatrix4(L, 2);
        *out = Vectormath::Aos::orthoInverse(*in);
    }

    return 0;
}

static int xMath_matrix_perspective(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        float fov = (float) luaL_checknumber(L, 2);
        float aspect = (float) luaL_checknumber(L, 3);
        float near_z = (float) luaL_checknumber(L, 4);
        float far_z = (float) luaL_checknumber(L, 5);
        if (near_z == 0.0f) near_z = 0.00001f;
        *out = Vectormath::Aos::Matrix4::perspective(fov, aspect, near_z, far_z);
    }

    return 0;
}

static int xMath_matrix_rotation_x(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        float angle = (float) luaL_checknumber(L, 2);
        *out = Vectormath::Aos::Matrix4::rotationX(angle);
    }

    return 0;
}

static int xMath_matrix_rotation_y(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        float angle = (float) luaL_checknumber(L, 2);
        *out = Vectormath::Aos::Matrix4::rotationY(angle);
    }

    return 0;
}

static int xMath_matrix_rotation_z(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        float angle = (float) luaL_checknumber(L, 2);
        *out = Vectormath::Aos::Matrix4::rotationZ(angle);
    }

    return 0;
}

static int xMath_matrix_translation(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        if (dmScript::IsVector3(L, 2))
        {
            Vectormath::Aos::Vector3 *v = dmScript::CheckVector3(L, 2);
            *out = Vectormath::Aos::Matrix4::translation(*v);
        }
        else if (dmScript::IsVector4(L, 2))
        {
            Vectormath::Aos::Vector4 *v = dmScript::CheckVector4(L, 2);
            *out = Vectormath::Aos::Matrix4::translation(v->getXYZ());
        }
    }
    return 0;
}

static int xMath_quat_matrix4(lua_State* L)
{
    if (dmScript::IsQuat(L, 1))
    {
        Vectormath::Aos::Quat *out = dmScript::CheckQuat(L, 1);
        Vectormath::Aos::Matrix4 *m = dmScript::CheckMatrix4(L, 2);
        Vectormath::Aos::Matrix3 m3(m->getCol0().getXYZ(), m->getCol1().getXYZ(), m->getCol2().getXYZ());
        *out = Vectormath::Aos::Quat(m3);
    }

    return 0;
}

static int xMath_matrix4_compose(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        Vectormath::Aos::Vector3 translation(0, 0, 0);
        if (dmScript::IsVector3(L, 2))
        {
            translation = *dmScript::CheckVector3(L, 2);
        }
        else if (dmScript::IsVector4(L, 2))
        {
            translation = dmScript::CheckVector4(L, 2)->getXYZ();
        }
        Vectormath::Aos::Quat *rotation = dmScript::CheckQuat(L, 3);
        Vectormath::Aos::Vector3 *scale = dmScript::CheckVector3(L, 4);

        Vectormath::Aos::Matrix3 rotationMatrix = Vectormath::Aos::Matrix3(*rotation);
        Vectormath::Aos::Matrix3 scaleMatrix = Vectormath::Aos::Matrix3::scale(*scale);
        Vectormath::Aos::Matrix3 rs = rotationMatrix * scaleMatrix;
        
        *out = Vectormath::Aos::Matrix4(rs, translation);
    }

    return 0;
}

static int xMath_matrix4_scale(lua_State* L)
{
    if (dmScript::IsMatrix4(L, 1))
    {
        Vectormath::Aos::Matrix4 *out = dmScript::CheckMatrix4(L, 1);
        int nargs = lua_gettop(L);
        
        if (nargs == 2)
        {
            if (dmScript::IsVector3(L, 2))
            {
                Vectormath::Aos::Vector3 *scale = dmScript::CheckVector3(L, 2);
                *out = Vectormath::Aos::Matrix4::scale(*scale);
            }
            else if (lua_isnumber(L, 2))
            {
                float s = (float) luaL_checknumber(L, 2);
                *out = Vectormath::Aos::Matrix4::scale(Vectormath::Aos::Vector3(s, s, s));
            }
        }
        else if (nargs == 4)
        {
            float x = (float) luaL_checknumber(L, 2);
            float y = (float) luaL_checknumber(L, 3);
            float z = (float) luaL_checknumber(L, 4);
            *out = Vectormath::Aos::Matrix4::scale(Vectormath::Aos::Vector3(x, y, z));
        }
    }

    return 0;
}

static inline float clamp_value(float value, float min_val, float max_val)
{
    if (value < min_val) return min_val;
    if (value > max_val) return max_val;
    return value;
}

static int xMath_clamp(lua_State* L)
{
    int nargs = lua_gettop(L);
    
    if (nargs >= 3 && lua_isnumber(L, 1))
    {
        // clamp(value, min, max) for numbers - returns clamped number
        float value = (float) luaL_checknumber(L, 1);
        float min_val = (float) luaL_checknumber(L, 2);
        float max_val = (float) luaL_checknumber(L, 3);
        lua_pushnumber(L, clamp_value(value, min_val, max_val));
        return 1;
    }
    else if (dmScript::IsVector3(L, 1))
    {
        // clamp(out, value, min, max) for vectors - modifies out in place
        Vectormath::Aos::Vector3 *out = dmScript::CheckVector3(L, 1);
        Vectormath::Aos::Vector3 *value = dmScript::CheckVector3(L, 2);
        
        float min_x, min_y, min_z;
        float max_x, max_y, max_z;
        
        if (dmScript::IsVector3(L, 3))
        {
            Vectormath::Aos::Vector3 *min_v = dmScript::CheckVector3(L, 3);
            min_x = min_v->getX();
            min_y = min_v->getY();
            min_z = min_v->getZ();
        }
        else
        {
            float min_val = (float) luaL_checknumber(L, 3);
            min_x = min_y = min_z = min_val;
        }
        
        if (dmScript::IsVector3(L, 4))
        {
            Vectormath::Aos::Vector3 *max_v = dmScript::CheckVector3(L, 4);
            max_x = max_v->getX();
            max_y = max_v->getY();
            max_z = max_v->getZ();
        }
        else
        {
            float max_val = (float) luaL_checknumber(L, 4);
            max_x = max_y = max_z = max_val;
        }
        
        out->setX(clamp_value(value->getX(), min_x, max_x));
        out->setY(clamp_value(value->getY(), min_y, max_y));
        out->setZ(clamp_value(value->getZ(), min_z, max_z));
    }
    else if (dmScript::IsVector4(L, 1))
    {
        Vectormath::Aos::Vector4 *out = dmScript::CheckVector4(L, 1);
        Vectormath::Aos::Vector4 *value = dmScript::CheckVector4(L, 2);
        
        float min_x, min_y, min_z, min_w;
        float max_x, max_y, max_z, max_w;
        
        if (dmScript::IsVector4(L, 3))
        {
            Vectormath::Aos::Vector4 *min_v = dmScript::CheckVector4(L, 3);
            min_x = min_v->getX();
            min_y = min_v->getY();
            min_z = min_v->getZ();
            min_w = min_v->getW();
        }
        else
        {
            float min_val = (float) luaL_checknumber(L, 3);
            min_x = min_y = min_z = min_w = min_val;
        }
        
        if (dmScript::IsVector4(L, 4))
        {
            Vectormath::Aos::Vector4 *max_v = dmScript::CheckVector4(L, 4);
            max_x = max_v->getX();
            max_y = max_v->getY();
            max_z = max_v->getZ();
            max_w = max_v->getW();
        }
        else
        {
            float max_val = (float) luaL_checknumber(L, 4);
            max_x = max_y = max_z = max_w = max_val;
        }
        
        out->setX(clamp_value(value->getX(), min_x, max_x));
        out->setY(clamp_value(value->getY(), min_y, max_y));
        out->setZ(clamp_value(value->getZ(), min_z, max_z));
        out->setW(clamp_value(value->getW(), min_w, max_w));
    }

    return 0;
}


//* Native Extension Bindings
//* ----------------------------------------------------------------------------

static const luaL_reg xMathModule_methods[] =
{
    //* Arithmetic
    {"add", xMath_add},
    {"sub", xMath_sub},
    {"mul", xMath_mul},
    {"div", xMath_div},
    //* Vector
    {"cross", xMath_cross},
    {"mul_per_elem", xMath_mul_per_elem},
    {"normalize", xMath_normalize},
    {"rotate", xMath_rotate},
    {"vector", xMath_vector},
    //* Quat
    {"conj", xMath_conj},
    {"quat_axis_angle", xMath_quat_axis_angle},
    {"quat_basis", xMath_quat_basis},
    {"quat_from_to", xMath_quat_from_to},
    {"quat_rotation_x", xMath_quat_rotation_x},
    {"quat_rotation_y", xMath_quat_rotation_y},
    {"quat_rotation_z", xMath_quat_rotation_z},
    {"quat", xMath_quat},
    {"quat_matrix4", xMath_quat_matrix4},
    //* Vector + Quat
    {"lerp", xMath_lerp},
    {"slerp", xMath_slerp},
    //* Matrix
    {"matrix", xMath_matrix},
    {"matrix_axis_angle", xMath_matrix_axis_angle},
    {"matrix_from_quat", xMath_matrix_from_quat},
    {"matrix_frustum", xMath_matrix_frustum},
    {"matrix_inv", xMath_matrix_inv},
    {"matrix_look_at", xMath_matrix_look_at},
    {"matrix4_orthographic", xMath_matrix_orthographic},
    {"matrix_ortho_inv", xMath_matrix_ortho_inv},
    {"matrix4_perspective", xMath_matrix_perspective},
    {"matrix_rotation_x", xMath_matrix_rotation_x},
    {"matrix_rotation_y", xMath_matrix_rotation_y},
    {"matrix_rotation_z", xMath_matrix_rotation_z},
    {"matrix_translation", xMath_matrix_translation},
    {"matrix4_compose", xMath_matrix4_compose},
    {"matrix4_scale", xMath_matrix4_scale},
    //* Utility
    {"clamp", xMath_clamp},
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
