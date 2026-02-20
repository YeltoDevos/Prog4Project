#include "ImageComponent.h"
#include "Texture2D.h"
#include "ResourceManager.h"

dae::ImageComponent::ImageComponent(GameObject& parent):
	BaseComponent(parent)
{

}

void dae::ImageComponent::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

std::shared_ptr<dae::Texture2D> dae::ImageComponent::GetTexture()
{
	return m_texture;
}
