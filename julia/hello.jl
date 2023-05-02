import Parameters: @with_kw, @with_kw_noshow

nzero(n) = tuple(zeros(n)...)

@with_kw mutable struct Leaf
  x::Cdouble = 1.0
  y::Vector{Cdouble} = zeros(5)
  z::Vector{Cdouble} = zeros(5)
  # y::NTuple{5,Cdouble} = nzero(5)
  # z::NTuple{5,Cdouble} = nzero(5)
end

const lib = "libleaf.dll"

# @ccall lib.hello()::Cvoid
ccall((:hello, lib), Cvoid, ())
l = Leaf()


# ccall((:hello, lib), Cvoid, ())
@ccall lib.init_leaf_struct(Ref(l)::Ptr{Leaf})::Cvoid
@ccall lib.set_2th_value(Ref(l)::Ptr{Leaf}, 3.0::Cdouble)::Cvoid

l.y[1] = 999.0
@ccall lib.show(Ref(l)::Ptr{Leaf})::Cvoid

# @ccall lib.init_leaf_struct2(Ref(l)::Ptr{Leaf})::Cvoid
# @show l
# @show l.y

# julia unable to change the value of C array
