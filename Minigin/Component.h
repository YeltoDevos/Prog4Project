#pragma once
#include <memory>
#include <string>
#include <SDL3_ttf/SDL_ttf.h>
#include "Transform.h"
#include "Font.h"
#include "Texture2D.h"

namespace dae
{
	class BaseComponent
	{
	public:
		BaseComponent();

		virtual void Update(){}
		virtual void Render(){}
	
	private:

	};

	class DerivedComponent : public BaseComponent
	{
	public:
		DerivedComponent() = default;

	private:

	};

	class SecondDerivedComponent : public BaseComponent
	{
	public:
		SecondDerivedComponent() = default;
	};

	class TransformComponent : public BaseComponent
	{

	};

	class RenderComponent : public BaseComponent
	{
	public:
		explicit RenderComponent();


		virtual void Render() override;

	private:
		std::string m_text{"Test Test"};
		SDL_Color m_color{ 255, 255, 255, 255 };
		Transform m_transform{};
		std::shared_ptr<Font> m_font{};
		std::shared_ptr<Texture2D> m_textTexture{};
	};

	class TextComponent : public BaseComponent
	{
	public:
		explicit TextComponent(std::string text);

		std::string GetText();

	private:
		std::string m_Text;
	};

	class FPSComponent : public BaseComponent
	{

	};
}