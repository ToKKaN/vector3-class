#pragma once
#include <cmath>

class vector3
{
public:
	typedef float vec_t;

	vec_t x, y, z;
	vector3() :
		x(0.0f),
		y(0.0f),
		z(0.0f)
	{
		
	}
	vector3( const vec_t x_in, const vec_t y_in, const vec_t z_in ) :
		x(x_in),
		y(y_in),
		z(z_in)
	{
		
	}
	explicit vector3( const vec_t xyz ) :
		x( xyz ),
		y( xyz ),
		z( xyz )
	{
		
	}

	__forceinline vec_t* base()
	{
		return reinterpret_cast< vec_t* >( this );
	}
	__forceinline vec_t const* base() const
	{
		return reinterpret_cast< vec_t const* >( this );
	}


	__forceinline bool operator==( const vector3& v_in ) const
	{
		return ( v_in.x == x ) && ( v_in.y == y ) && ( v_in.z == z );
	}
	__forceinline bool operator!=( const vector3& v_in ) const
	{
		return ( v_in.x != x ) || ( v_in.y != y ) || ( v_in.z != z );
	}

	__forceinline vec_t operator[]( const int in ) const
	{
		return reinterpret_cast< const vec_t* >( this )[ in ];
	}
	__forceinline vec_t& operator[]( const int in )
	{
		return reinterpret_cast< vec_t* >( this )[ in ];
	}

	__forceinline vector3& operator+=( const vector3& v_in )
	{
		x += v_in.x;
		y += v_in.y;
		z += v_in.z;
		return *this;
	}
	__forceinline vector3& operator-=( const vector3& v_in )
	{
		x -= v_in.x;
		y -= v_in.y;
		z -= v_in.z;
		return *this;
	}
	__forceinline vector3& operator*=( const vector3& v_in )
	{
		x *= v_in.x;
		y *= v_in.y;
		z *= v_in.z;
		return *this;
	}
	__forceinline vector3& operator/=( const vector3& v_in )
	{
		x /= v_in.x;
		y /= v_in.y;
		z /= v_in.z;
		return *this;
	}

	__forceinline vector3& operator+=( const float in )
	{
		x += in;
		y += in;
		z += in;
		return *this;
	}
	__forceinline vector3& operator-=( const float in )
	{
		x -= in;
		y -= in;
		z -= in;
		return *this;
	}
	__forceinline vector3& operator*=( const float in )
	{
		x *= in;
		y *= in;
		z *= in;
		return *this;
	}
	__forceinline vector3& operator/=( const float in )
	{
		x /= in;
		y /= in;
		z /= in;
		return *this;
	}

	__forceinline vector3& operator=( const vector3& v_in ) = default;

	__forceinline vector3 operator-() const
	{
		return vector3( -x, -y, -z );
	}
	__forceinline vector3 operator+( const vector3& v_in ) const
	{
		return vector3( x + v_in.x, y + v_in.y, z + v_in.z );
	}
	__forceinline vector3 operator-( const vector3& v_in ) const
	{
		return vector3( x - v_in.x, y - v_in.y, z - v_in.z );
	}
	__forceinline vector3 operator*( const vector3& v_in ) const
	{
		return vector3( x * v_in.x, y * v_in.y, z * v_in.z );
	}
	__forceinline vector3 operator/( const vector3& v_in ) const
	{
		return vector3( x / v_in.x, y / v_in.y, z / v_in.z );
	}

	__forceinline vector3 operator*( const float in ) const
	{
		return vector3( x * in, y * in, z * in );
	}
	__forceinline vector3 operator/( const float in ) const
	{
		return vector3( x / in, y / in, z / in );
	}


	__forceinline void			zero()
	{
		x = y = z = 0.0f;
	}
	__forceinline bool			is_zero( const float tolerance = 0.001f ) const
	{
		return ( x > -tolerance ) && ( x < tolerance ) &&
			   ( y > -tolerance ) && ( y < tolerance ) && 
			   ( z > -tolerance ) && ( z < tolerance );
	}
	__forceinline void			negate()
	{
		x = -x;
		y = -y;
		z = -z;
	}
	__forceinline vector3		cross( const vector3& v_in ) const
	{
		return vector3( y * v_in.z - z * v_in.y,
						z * v_in.x - x * v_in.z,
						x * v_in.y - y * v_in.x );
	}
	__forceinline float			dot( const vector3& v_in ) const
	{
		return ( x * v_in.x + y * v_in.y + z * v_in.z );
	}
	__forceinline float			length() const
	{
		return sqrt( x*x + y * y + z * z );
	}
	__forceinline float			distance_to( const vector3& v_in ) const
	{
		return vector3( x - v_in.x, y - v_in.y, z - v_in.z ).length();
	}
	__forceinline vector3		_min( const vector3& v_in ) const
	{
		return vector3( x < v_in.x ? x : v_in.x,
						y < v_in.y ? y : v_in.y,
						z < v_in.z ? z : v_in.z );
	}
	__forceinline vector3		_max( const vector3& v_in ) const
	{
		return vector3( x > v_in.x ? x : v_in.x,
						y > v_in.y ? y : v_in.y,
						z > v_in.z ? z : v_in.z );
	}

	~vector3() = default;
};
