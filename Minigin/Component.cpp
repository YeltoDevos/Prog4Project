#include <string>
#include "Component.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "Texture2D.h"
#include "GameObject.h"

dae::BaseComponent::BaseComponent(GameObject& owner):
	m_owner{owner}
{
}
