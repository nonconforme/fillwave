/*
 * ScenePerspective.h
 *
 *  Created on: 6 May 2015
 *      Author: Filip Wasil
 */

#ifndef ScenePerspective_H_
#define ScenePerspective_H_

#include <fillwave/space/base/IScene.h>
#include <fillwave/space/CameraPerspective.h>

namespace fillwave {
namespace framework {

/*! \class ScenePerspective
 * \brief Scene with perspective projection.
 *
 */

class ScenePerspective: public IScene {
public:
	ScenePerspective(pCameraPerspective camera = pCameraPerspective());
	virtual ~ScenePerspective() = default;
	void setCamera(pCameraPerspective camera);
	pICamera getCamera();

	void draw();
	void drawPicking();
	void drawDepthInt();
	void drawOcclusion();

private:
	pCameraPerspective mCamera;
};

} /* framework */

typedef std::shared_ptr<framework::ScenePerspective> pScenePerspective;

static pScenePerspective buildScenePerspective(pCameraPerspective camera =
		pCameraPerspective()) {
	return std::make_shared<framework::ScenePerspective>(camera);
}
} /* fillwave */
#endif /* ScenePerspective_H_ */