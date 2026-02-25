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

#include <filesystem>
namespace fs = std::filesystem;

static void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene();

	auto go = std::make_unique<dae::GameObject>();
	go->SetTexture("background.png");
	scene.Add(std::move(go));

	auto background = std::make_unique<dae::GameObject>();
	background->AddComponent<dae::ImageComponent>();
	background->GetComponent<dae::ImageComponent>()->SetTexture("background.png");
	background->AddComponent<dae::RenderComponent>();
	background->GetComponent<dae::RenderComponent>()->SetTexture(background->GetComponent<dae::ImageComponent>()->GetTexture());
	scene.Add(std::move(background));

	go = std::make_unique<dae::GameObject>();
	go->SetTexture("logo.png");
	go->SetPosition(358, 180);
	scene.Add(std::move(go));

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_unique<dae::TextObject>("Programming 4 Assignment", font);
	to->SetColor({ 255, 255, 0, 255 });
	to->SetPosition(292, 20);
	scene.Add(std::move(to));

	auto test = std::make_unique<dae::GameObject>();
	test->AddComponent<dae::FPSComponent>();
	test->AddComponent<dae::TextComponent>();
	test->AddComponent<dae::RenderComponent>();
	test->GetComponent<dae::RenderComponent>()->SetTexture(test->GetComponent<dae::TextComponent>()->GetTexture());
	scene.Add(std::move(test));

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
