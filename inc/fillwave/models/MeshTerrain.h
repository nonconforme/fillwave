/*
 * MeshTerrain.h
 *
 *  Created on: Apr 20, 2015
 *      Author: Filip Wasil
 */

#ifndef INC_FILLWAVE_TERRAIN_MESHTERRAIN_H_
#define INC_FILLWAVE_TERRAIN_MESHTERRAIN_H_

#include <fillwave/models/Mesh.h>
#include <fillwave/models/base/Programmable.h>
#include <fillwave/models/terrain/TerrainConstructor.h>

namespace fillwave {
class Engine;
namespace framework {

/*! \class MeshTerrain
 * \brief Programmable to provide mesh terrain functionality.
 */

class MeshTerrain: public Programmable {
public:
	MeshTerrain(
			Engine* engine,
			pProgram program,
			TerrainConstructor* constructor,
			const Material& material,
			const std::string& diffuseMapPath,
			const std::string& normalMapPath,
			const std::string& specularMapPath,
			GLuint radius,
			GLuint density = 8);

	MeshTerrain(
			Engine* engine,
			pProgram program,
			TerrainConstructor* constructor,
			const Material& material,
			pTexture2D diffuseMapPath,
			pTexture2D normalMapPath,
			pTexture2D specularMapPath,
			GLuint radius,
			GLuint density = 8);

	virtual ~MeshTerrain() = default;

	void draw(ICamera& camera);
	void drawPBRP(ICamera& camera);

	void updateRenderer(IRenderer& renderer);

private:
	LightManager* mLightManager;
	GLfloat mChunkWidth;
	GLfloat mJumpStep;

	void distanceCheck(ICamera& camera);
};

} /* framework */
typedef std::shared_ptr<framework::MeshTerrain> pMeshTerrain;
} /* fillwave */

#endif /* INC_FILLWAVE_TERRAIN_MESHTERRAIN_H_ */