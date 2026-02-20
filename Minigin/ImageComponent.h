#pragma once
#include "Component.h"

namespace dae
{
	class ImageComponent : public BaseComponent
	{
	public:
		ImageComponent(GameObject& parent);

		virtual void Update() override{}

		void SetTexture(const std::string& filename);
		std::shared_ptr<Texture2D> GetTexture();

	private:
		std::shared_ptr<Texture2D> m_texture{};


	};
}