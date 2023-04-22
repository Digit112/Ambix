
namespace amb::ren {
	tri_mesh::tri_mesh(uint16_t num_verts, uint32_t num_tris) : {
		num_verts = new vert[num_verts];
		num_tris = new tri[num_tris];
	}
	
	tri_mesh::tri_mesh(prim p) {
		switch (p) {
			case prim::cube:
				num_verts = new float[8];
				num_tris = new uint16_t[12];
				
				verts[0] = {-1, -1, -1};
				verts[1] = {-1, -1,  1};
				verts[2] = {-1,  1, -1};
				verts[3] = {-1,  1,  1};
				verts[4] = { 1, -1, -1};
				verts[5] = { 1, -1,  1};
				verts[6] = { 1,  1, -1};
				verts[7] = { 1,  1,  1};
				
				// 0 1 2 3
				tris[0]  = {0, 1, 2}; // x-
				tris[1]  = {1, 3, 2};
				
				// 7 6 5 4
				tris[2]  = {6, 5, 4}; // x+
				tris[3]  = {6, 7, 5};
				
				// 0 1 4 5
				tris[4]  = {4, 1, 0}; // y-
				tris[5]  = {4, 5, 1};
				
				// 7 6 3 2
				tris[6]  = {7, 6, 3}; // y+
				tris[7]  = {6, 2, 3};
				
				// 0 2 4 6
				tris[8]  = {0, 2, 4}; // z-
				tris[9]  = {2, 6, 4};
				
				// 1 3 5 7
				tris[10] = {3, 5, 7}; // z+
				tris[11] = {3, 1, 5};

				break;
		}
	}
	
	tri_mesh::~tri_mesh {
		delete[] num_verts;
		delete[] num_tris;
	}
} // amb::ren