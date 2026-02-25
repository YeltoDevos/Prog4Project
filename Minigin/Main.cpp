#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#if _DEBUG && __has_include(<vld.h>)
#include <vld.h>
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "Scene.h"

#include "RenderComponent.h"
#include "TextComponent.h"
#include "ImageComponent.h"
#include "FPSComponent.h"
#include "TranslateComponents.h"

#include <filesystem>
namespace fs = std::filesystem;

static void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene();

	auto background{ std::make_unique<dae::GameObject>() };
	background->AddComponent<dae::ImageComponent>();
	background->GetComponent<dae::ImageComponent>()->SetTexture("background.png");
	background->AddComponent<dae::RenderComponent>();
	background->GetComponent<dae::RenderComponent>()->SetTexture(background->GetComponent<dae::ImageComponent>()->GetTexture());
	scene.Add(std::move(background));

	auto logo{ std::make_unique<dae::GameObject>() };
	logo->AddComponent<dae::ImageComponent>();
	logo->GetComponent<dae::ImageComponent>()->SetTexture("logo.png");
	logo->AddComponent<dae::TransformComponent>();
	logo->GetComponent<dae::TransformComponent>()->SetPosition(358, 180);
	logo->AddComponent<dae::RenderComponent>();
	logo->GetComponent<dae::RenderComponent>()->SetTexture(logo->GetComponent<dae::ImageComponent>()->GetTexture());
	scene.Add(std::move(logo));

	auto title{ std::make_unique<dae::GameObject>() };
	title->AddComponent<dae::TextComponent>();
	title->GetComponent<dae::TextComponent>()->SetText("Programming 4 Assignment");
	title->AddComponent<dae::TransformComponent>();
	title->GetComponent<dae::TransformComponent>()->SetPosition(292, 20);
	title->AddComponent<dae::RenderComponent>();
	scene.Add(std::move(title));

	auto fps{ std::make_unique<dae::GameObject>() };
	fps->AddComponent<dae::FPSComponent>();
	fps->AddComponent<dae::TextComponent>();
	fps->AddComponent<dae::RenderComponent>();
	fps->GetComponent<dae::RenderComponent>()->SetTexture(fps->GetComponent<dae::TextComponent>()->GetTexture());
	scene.Add(std::move(fps));

	auto player{ std::make_unique<dae::GameObject>() };
	player->AddComponent<dae::ImageComponent>();
	player->GetComponent<dae::ImageComponent>()->SetTexture("PeterPepper.png");
	player->AddComponent<dae::TransformComponent>();
	player->GetComponent<dae::TransformComponent>()->SetPosition(250, 400);
	player->AddComponent<dae::RenderComponent>();
	player->GetComponent<dae::RenderComponent>()->SetTexture(player->GetComponent<dae::ImageComponent>()->GetTexture());
	scene.Add(std::move(player));

}

int main(int, char*[]) {
#if __EMSCRIPTEN__
	fs::path data_location = "";
#else
	fs::path data_location = "./Data/";
	if(!fs::exists(data_location))
		data_location = "../Data/";
#endif
	dae::Minigin engine(data_location);
	engine.Run(load);
    return 0;
}
