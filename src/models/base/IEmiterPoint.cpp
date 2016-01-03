/*
 * IEmiterPoint.cpp
 *
 *  Created on: 16 Jun 2014
 *      Author: Filip Wasil
 */

#include <fillwave/Fillwave.h>
#include <fillwave/models/base/IEmiterPoint.h>

FLOGINIT("Emiter", FERROR | FFATAL)

namespace fillwave {
namespace framework {

IEmiterPoint::IEmiterPoint(
		Engine* engine,
		GLuint howMany,
		GLfloat size,
		GLfloat lifetime,
		pTexture texture,
		glm::vec4 color,
		GLenum blendingSource,
		GLenum blendingDestination,
		GLboolean depthTesting,
		GLfloat alphaCutOff)
		:
				Reloadable(engine),
				mStartSize(size),
				mLifetime(lifetime),
				mTexture(texture),
				mColor(color),
				mHowMany(howMany),
				mDepthTesting(depthTesting),
				mAlphaCutOff(alphaCutOff) {
	mBlending.mSource = blendingSource;
	mBlending.mDestination = blendingDestination;

#ifdef FILLWAVE_GLES_3_0
#else
	glEnable(GL_PROGRAM_POINT_SIZE);
	// glEnable(GL_POINT_SPRITE) always on since OpenGL 3.2 ... but not at all drivers ://////
	glEnable(GL_POINT_SPRITE);
#endif
}

void IEmiterPoint::setBlendingFunction(
		GLenum sourceFactor,
		GLenum destinationFactor) {
	mBlending.mSource = sourceFactor;
	mBlending.mDestination = destinationFactor;
}

void IEmiterPoint::updateRenderpass(std::unordered_map<GLuint, std::vector<Entity*> >& renderpasses) {
	GLuint handle = mProgram.get()->getHandle();
	if (renderpasses.find(handle) != renderpasses.end()) {
		renderpasses[handle].push_back(this);
	} else {
		std::vector<Entity*> vector; /* xxx some base size maybe ? */
		vector.push_back(this);
		renderpasses[handle] = vector;
	}
}

} /* framework */
} /* fillwave */
