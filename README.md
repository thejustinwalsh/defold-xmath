# xMath Extension
> Defold Math Library ❌ ~~allocations~~

A re-imagining of vmath functions that avoid allocations by taking the output as the first argument instead of returning a new Vector3, Vector4, or Quat requiring an allocation.

```lua
go.property("dir", vmath.vector3(0, 1, 0))

-- allocate v once and reuse each update
local v = vmath.vector3();

function update(self, dt)
  local pos = go.get_position();

  xmath.mul(v, self.dir, 5 * dt); -- save 1 allocation 
  xmath.add(v, pos, v);           -- save 2 allocations

  go.set_position(v);
end
```

## Demo
https://thejustinwalsh.com/defold-xmath/
