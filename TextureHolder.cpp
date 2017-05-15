#include "TextureHolder.h"

namespace Textures {

	//regular resource load just like textures etc
	template <typename Resource, typename Identifier>
	void ResourceHolder<Resource,Identifier>::load(Identifier id, const std::string &filename) {
		std::unique_ptr<Resource> resource(new Resource());
		if (!resource->loadFromFile(filename))
			throw std::runtime_error("TextureHolder::load - Failed to load " + filename);

		auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
		assert(inserted.second);
	}

	//music load, has to have an additional parameter
	template <typename Resource, typename Identifier>
	template <typename Parameter>
	void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string &filename, const Parameter& secondParam) {
		std::unique_ptr<Resource> resource(new Resource());
		if (!resource->loadFromFile(filename, secondParam))
			throw std::runtime_error("TextureHolder::load - Failed to load " + filename);

		auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
		assert(inserted.second);
	}

	template <typename Resource, typename Identifier>
	Resource& ResourceHolder::get(Identifier id) {
		auto found = mResourceMap.find(id);
		assert(found != mResourceMap.end());

		return *found->second;
	}

	template <typename Resource, typename Identifier>
	const Resource& ResourceHolder::get(Identifier id) const {
		auto found = mResourceMap.find(id);
		assert(found != mResourceMap.end());

		return *found->second;
	}



}