/*
 * IRenderer.cpp
 *
 *  Created on: Jan 31, 2016
 *      Author: filip
 */

#ifndef TESTS_MOCKS_IRENDERER_CPP_
#define TESTS_MOCKS_IRENDERER_CPP_

/*
 * Button.cpp
 *
 *  Created on: Jan 21, 2016
 *      Author: filip
 */

#pragma once

#include <fillwave/renderers/IRenderer.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace fillwave;
using namespace fillwave::framework;

class MockIRenderer: public IRenderer {
public:
	MOCK_METHOD1(update, void(IRenderable* renderable));
	MOCK_METHOD1(draw, void(ICamera& camera));
	MOCK_METHOD2(onPicked, void(GLuint width, GLuint height));
	MOCK_METHOD0(onUnpicked, void());
};

#endif /* TESTS_MOCKS_IRENDERER_CPP_ */
