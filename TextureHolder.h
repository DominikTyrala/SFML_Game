#ifndef TEXTURE_HOLDER
#define TEXTURE_HOLDER

#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <cassert>

namespace Textures {
	enum ID {Landscape, Airplane, Missile};

	template <typename Resource, typename Identifier>
	class ResourceHolder {
		private:
			std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;

		public:
			void load(Identifier id, const std::string &filename);
			Resource& get(Identifier id);
			const Resource& get(Identifier id) const;
	};
}

#endif // !TEXTURE_HOLDER

