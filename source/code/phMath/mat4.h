#pragma once

#include "vec3.h"

namespace pm
{

class mat4
{
public:

	// Sets all values to 0 as default
	mat4();
	mat4( const mat4& other );

	// Defaults all values to 0, except the diagonal.
	// ie. pmMat4( 1.0f ) creates an identity matrix.
	// ASCII ART TIME!
	// [1 0 0 0]
	// [0 1 0 0]
	// [0 0 1 0]
	// [0 0 0 1]
	mat4( const float diagonal );

	~mat4();

	union
	{
		// Single elements of the matrix
		float elements[16];

		// Matrix represented as directional vectors and translation
		struct
		{
			// Instead of using padding floats, we align the vectors with 16 bytes
			_declspec( align(16) ) vec3 left;
			_declspec( align(16) ) vec3 up;
			_declspec( align(16) ) vec3 forward;
			_declspec( align(16) ) vec3 translation;
		};
	};

	void Translate( const vec3& translation );
	void RotateZYX( const vec3& axis ); // Recommended for camera rotation
	void RotateXYZ( const vec3& axis );
	void Scale( const vec3& scale );
	void Transpose();

	mat4 GetViewMatrix() const;
	mat4 GetInverse() const;

	static mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
	static mat4 Perspective(float fov, float aspectRatio, float near, float far);

	mat4 operator * ( const mat4& other );

};

}