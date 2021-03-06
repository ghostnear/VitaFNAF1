#include "asset_manager.hpp"

namespace Engine::Game
{
    Assets::ImageAsset* AssetManager::loadImage(std::string path, std::string name, SDL_Renderer* renderer)
    {
        // Save the newly created asset here
        Assets::ImageAsset* asset = new Assets::ImageAsset(path, renderer);
        assets[name] = asset;
        return asset;
    }

    Assets::AudioAsset* AssetManager::loadMP3(std::string path, std::string name)
    {
        // Save the newly created asset here
        Assets::AudioAsset* asset = new Assets::AudioAsset();
        asset -> loadMP3(path);
        assets[name] = asset;
        return asset;
    }

    Asset* AssetManager::getAsset(std::string name)
    {
        // Return the required asset pointer
        return assets[name];
    }
};