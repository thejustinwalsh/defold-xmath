---xMath Extension
---Allocation-free re-implementation of Defold's vmath module — most functions write into their first (output) argument in place; some overloads (e.g. lerp/clamp for numbers) return a number.
---@class xmath
xmath = {}

--* Arithmetic
--* ----------------------------------------------------------------------------

---Add one vector to another.
---@param v_in_place vector3|vector4
---@param v1 vector3|vector4
---@param v2 vector3|vector4
function xmath.add(v_in_place, v1, v2) end

---Subtract one vector from another.
---@param v_in_place vector3|vector4
---@param v1 vector3|vector4
---@param v2 vector3|vector4
function xmath.sub(v_in_place, v1, v2) end

---Multiply a vector by a scalar.
---@param v_in_place vector3|vector4
---@param v vector3|vector4
---@param n number
function xmath.mul(v_in_place, v, n) end

---Divide a vector by a scalar.
---@param v_in_place vector3|vector4
---@param v vector3|vector4
---@param n number
function xmath.div(v_in_place, v, n) end

--* Vector
--* ----------------------------------------------------------------------------

---Calculate the cross product of two vectors.
---@param v_in_place vector3
---@param v1 vector3
---@param v2 vector3
function xmath.cross(v_in_place, v1, v2) end

---Perform element-wise multiplication between two vectors.
---@param v_in_place vector3|vector4
---@param v1 vector3|vector4
---@param v2 vector3|vector4
function xmath.mul_per_elem(v_in_place, v1, v2) end

---Normalize a vector.
---@param v_in_place vector3|vector4
---@param v1 vector3|vector4
function xmath.normalize(v_in_place, v1) end

---Rotate a vector by a quaternion.
---@param v_in_place vector3
---@param q quaternion
---@param v1 vector3
function xmath.rotate(v_in_place, q, v1) end

---Set the value of a vector to (0, 0, 0) or (0, 0, 0, 1).
---@param v_in_place vector3|vector4
function xmath.vector(v_in_place) end

--* Quat
--* ----------------------------------------------------------------------------

---Calculate the conjugate of a quaternion.
---@param q_in_place quaternion
---@param q1 quaternion
function xmath.conj(q_in_place, q1) end

---Set the value of a quaternion from an axis and an angle.
---@param q_in_place quaternion
---@param v vector3
---@param angle number
function xmath.quat_axis_angle(q_in_place, v, angle) end

---Set the value of a quaternion from x, y, and z base unit vectors.
---@param q_in_place quaternion
---@param x vector3
---@param y vector3
---@param z vector3
function xmath.quat_basis(q_in_place, x, y, z) end

---Set the value of a quaternion to rotate from one vector to another.
---@param q_in_place quaternion
---@param v1 vector3
---@param v2 vector3
function xmath.quat_from_to(q_in_place, v1, v2) end

---Set the value of a quaternion for rotation around the x-axis.
---@param q_in_place quaternion
---@param angle number
function xmath.quat_rotation_x(q_in_place, angle) end

---Set the value of a quaternion for rotation around the y-axis.
---@param q_in_place quaternion
---@param angle number
function xmath.quat_rotation_y(q_in_place, angle) end

---Set the value of a quaternion for rotation around the z-axis.
---@param q_in_place quaternion
---@param angle number
function xmath.quat_rotation_z(q_in_place, angle) end

---Set the value of a quaternion to (0, 0, 0, 1).
---@param q_in_place quaternion
function xmath.quat(q_in_place) end

---Set the value of a quaternion from a matrix4.
---@param q_in_place quaternion
---@param m matrix4
function xmath.quat_matrix4(q_in_place, m) end

---Set the value of a quaternion from Euler angles (in degrees, YZX rotation order).
---@param q_in_place quaternion
---@param x number
---@param y number
---@param z number
---@overload fun(q_in_place: quaternion, euler: vector3)
function xmath.euler_to_quat(q_in_place, x, y, z) end

--* Vector + Quat
--* ----------------------------------------------------------------------------

---Linearly interpolate between two numbers, vectors, or quaternions. For numbers, returns the interpolated number. For vectors/quaternions, modifies v_in_place instead.
---@param t number
---@param n1 number
---@param n2 number
---@return number
---@overload fun(v_in_place: vector3, t: number, v1: vector3, v2: vector3)
---@overload fun(v_in_place: vector4, t: number, v1: vector4, v2: vector4)
---@overload fun(v_in_place: quaternion, t: number, v1: quaternion, v2: quaternion)
function xmath.lerp(t, n1, n2) end

---Spherically interpolate between two vectors or quaternions.
---@param v_in_place vector3|vector4|quaternion
---@param t number
---@param v1 vector3|vector4|quaternion
---@param v2 vector3|vector4|quaternion
function xmath.slerp(v_in_place, t, v1, v2) end

--* Matrix
--* ----------------------------------------------------------------------------

---Set the value of a matrix to the identity matrix.
---@param m_in_place matrix4
---@overload fun(m_in_place: matrix4, m1: matrix4)
function xmath.matrix(m_in_place) end

---Set the value of a matrix for rotation around an axis by an angle.
---@param m_in_place matrix4
---@param v vector3
---@param angle number
function xmath.matrix_axis_angle(m_in_place, v, angle) end

---Set the value of a matrix from a quaternion.
---@param m_in_place matrix4
---@param q quaternion
function xmath.matrix_from_quat(m_in_place, q) end

---Set the value of a frustum matrix from given values.
---@param m_in_place matrix4
---@param left number
---@param right number
---@param bottom number
---@param top number
---@param near number
---@param far number
function xmath.matrix_frustum(m_in_place, left, right, bottom, top, near, far) end

---Calculate the inverse of a matrix.
---@param m_in_place matrix4
---@param m1 matrix4
function xmath.matrix_inv(m_in_place, m1) end

---Set the value of a matrix from supplied look-at parameters.
---@param m_in_place matrix4
---@param eye vector3
---@param look_at vector3
---@param up vector3
function xmath.matrix_look_at(m_in_place, eye, look_at, up) end

---Set the value of an orthographic projection matrix.
---@param m_in_place matrix4
---@param left number
---@param right number
---@param bottom number
---@param top number
---@param near number
---@param far number
function xmath.matrix4_orthographic(m_in_place, left, right, bottom, top, near, far) end

---The resulting matrix is the inverse of the supplied matrix.
---@param m_in_place matrix4
---@param m1 matrix4
function xmath.matrix_ortho_inv(m_in_place, m1) end

---Set the value of a perspective projection matrix.
---@param m_in_place matrix4
---@param fov number
---@param aspect number
---@param near number
---@param far number
function xmath.matrix4_perspective(m_in_place, fov, aspect, near, far) end

---Set the value of a matrix for rotation around the x-axis.
---@param m_in_place matrix4
---@param angle number
function xmath.matrix_rotation_x(m_in_place, angle) end

---Set the value of a matrix for rotation around the y-axis.
---@param m_in_place matrix4
---@param angle number
function xmath.matrix_rotation_y(m_in_place, angle) end

---Set the value of a matrix for rotation around the z-axis.
---@param m_in_place matrix4
---@param angle number
function xmath.matrix_rotation_z(m_in_place, angle) end

---Set the value of a matrix for translation.
---@param m_in_place matrix4
---@param position vector3|vector4
function xmath.matrix_translation(m_in_place, position) end

---Set the value of a matrix from translation, rotation and scale.
---@param m_in_place matrix4
---@param translation vector3|vector4
---@param rotation quaternion
---@param scale vector3
function xmath.matrix4_compose(m_in_place, translation, rotation, scale) end

---Set the value of a matrix from scale. Can take a vector3, a single number for uniform scale, or 3 numbers for x, y, z scale.
---@param m_in_place matrix4
---@param scale vector3
---@overload fun(m_in_place: matrix4, scale: number)
---@overload fun(m_in_place: matrix4, scale_x: number, scale_y: number, scale_z: number)
function xmath.matrix4_scale(m_in_place, scale) end

--* Utility
--* ----------------------------------------------------------------------------

---Clamp input value in range [min, max]. For numbers, returns the clamped number. For vectors, modifies v_in_place instead. min and max can be numbers or matching vector types.
---@param value number
---@param min number
---@param max number
---@return number
---@overload fun(v_in_place: vector3, value: vector3, min: vector3|number, max: vector3|number)
---@overload fun(v_in_place: vector4, value: vector4, min: vector4|number, max: vector4|number)
function xmath.clamp(value, min, max) end
