#include "Camera.h"

game::Camera::Camera() : Component(typeid(Camera).name())
{
	_view.setViewport(sf::FloatRect(0, 0, 1, 1));
	_view.setCenter(0.f, 0.f);
}

game::Camera::~Camera()
{

}

sf::View game::Camera::GetView()
{
	return _view;
}