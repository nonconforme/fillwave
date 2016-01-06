/*
 * Scene.h
 *
 *  Created on: May 2, 2014
 *      Author: Filip Wasil
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <fillwave/models/Entity.h>
#include <fillwave/models/Skybox.h>
#include <fillwave/models/Cursor.h>
#include <fillwave/models/Terrain.h>
#include <fillwave/models/base/IDrawable.h>
#include <fillwave/renderers/RendererFR.h>

namespace fillwave {
namespace framework {

/*! \class Scene
 * \brief Entity to be a root of Entity tree.
 */

class IScene : public TreePtr<pEntity> {
public:
	IScene(IRenderer* renderer = new RendererPBRP());

	virtual ~IScene() = default;

	void updateDependencies();
	void updateRenderer();

	/* Cursor */
	void setCursor(pCursor cursor);
	pCursor getCursor();
	void drawCursor();
	void moveCursor(glm::vec2 position);

	/* Scene */
	void setSkybox(pSkybox skybox);
	void setAmbient(glm::vec3 cursor);
	void setRenderer(IRenderer* renderer);

	/* Pickable */
	void registerPickable(pEntity entity);
	void pick(glm::ivec4 color);

	/* Events */
	void onEvent(EventType& event);

	void draw(ICamera& c);
	void drawDepth(ICamera& camera);
	void drawDepthColor(ICamera& camera, glm::vec3& position);

	/* Interface */
	virtual void draw() = 0;
	virtual void drawDepthInt() = 0;
	virtual void drawPicking() = 0;
	virtual void drawOcclusion() = 0;
	virtual pICamera getCamera() = 0;

	/* Optional */
	virtual void onShow();
	virtual void onHide();

protected:
	pCursor mCursor;
	pSkybox mSkybox;
	std::unordered_map<GLint, pEntity> mPickingTable;
	pEntity mLastPicked;
	glm::vec3 mAmbientGlobal;
	puIRenderer mRenderer;

private:
	const GLint MAXIMUM_TRIALS_TO_PICK_COLOR = 2000;
};

} /* framework */
typedef std::shared_ptr<framework::IScene> pIScene;
typedef std::unique_ptr<framework::IScene> puIScene;
} /* fillwave */

#endif /* SCENE_H_ */
