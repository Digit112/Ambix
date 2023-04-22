#ifndef AMBIX_REN_TRI_MESH
#define AMBIX_REN_TRI_MESH

#include <array>
#include <cstdio>
#include <cstdint>

#include "../utility_GPU/vec.hpp"

#include "primitives.hpp"

namespace amb::ren {
	/// Simplest and fastest-to-render representation of a mesh. Meshes are represented as a set of vertices
	/// and a set of triangles which use those vertices. Edges are not represented, although they can be inferred.
	/// Most operations that determine properties of the mesh or modify it are very slow and in particular they scale extremely poorly.
	/// However, these are very fast to render because it is trivial to enumerate the triangles. Additionally, they use minimal memory.
	/// Meshes are limited to 65,536 vertices.
	/// @brief Quick & simple mesh representation for fast rendering. Should almost always be used when rendering meshes.
	class tri_mesh {
	public:
		/// An x, y, z triple that represents a position.
		typedef struct {float x; float y; float z;} vert;
		
		/// Ana, b, c triple that represents a triangle of vert's
		typedef struct {uint16_t a; uint16_t b; uint16_t c;} tri;
		
		/// @brief The number of vertices in this mesh.
		uint16_t num_verts;
		
		/// @brief The number of triangle faces in this mesh.
		uint32_t num_tris;
		
		/// List of all vertices used by this mesh as x, y, z triplets.
		/// @brief List of vertices.
		vert* verts;
		
		/// List of all triangles as triplets of indexed vertices.
		/// @brief List of triangles.
		tri* tris;
		
		/// Create an uninitialized mesh capable of holding the given number of verts and tris.
		tri_mesh(uint16_t max_verts, uint32_t max_tris);
		
		~tri_mesh();
	};
} // amb::ren

#include "tri_mesh.cpp"

#endif