#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_

#include <string>
#include <unordered_map>
#include "texture.h"

using std::string;

class FontManager;

// TextureManager manages all kind of textures like sprites and rendered texts
// It acts like a cache for textures. A texture can be found with string key.
// FIXME Caching text textures may cause memory explosion

class TextureManager {
 public:
  TextureManager(Renderer* renderer, const string& scenario_path, const string& font_path);
  ~TextureManager();

 public:
  Texture* FetchTexture(const string&);
  Texture* FetchWhitenedTexture(const string&);
  Texture* FetchTextTexture(const string&, int, Color, uint32_t = 0);

 private:
  string base_path_;
  FontManager* font_manager_;
  std::unordered_map<string, Texture*> container_;
  Texture*  dummy_texture_;
  Renderer* renderer_;
};

#endif // TEXTURE_MANAGER_H_
