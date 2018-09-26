#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)

}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map




	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if (ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data

		DesertMap.width = map_file.child("map").attribute("width").as_uint();
		LOG("file loaded. Width: %d", DesertMap.width);
		DesertMap.height = map_file.child("map").attribute("height").as_uint();
		LOG("file loaded. Height: %d", DesertMap.height);
		DesertMap.tilewidth = map_file.child("map").attribute("tilewidth").as_uint();
		LOG("file loaded. Tilewidth: %d", DesertMap.tilewidth);
		DesertMap.tileheight = map_file.child("map").attribute("tileheight").as_uint();
		LOG("file loaded. TileHeight: %d", DesertMap.tileheight);

		p2SString orientationValue = map_file.child("map").attribute("orientation").as_string();


		if (orientationValue == "orthogonal") {
			DesertMap.orientation::orthogonal;
			LOG("file loaded. Orientation: Orthogonal");
		}
		else if (orientationValue == "isometric") {
			DesertMap.orientation::isometric;
			LOG("file loaded. Orientation: Isometric");
		}
		else if (orientationValue == "isometric staggered") {
			DesertMap.orientation::isometric_staggered;
			LOG("file loaded. Orientation: isometric staggered");
		}
		else if (orientationValue == "hexagonal staggered") {
			DesertMap.orientation::hexagonal_staggered;
			LOG("file loaded. Orientation: Hexagonal Staggered");
		}
		else {
			DesertMap.orientation::error;
			LOG("file loaded. error, couldnt load orientation");
		}

		p2SString RenderValue = map_file.child("map").attribute("renderorder").as_string();

		if (RenderValue == "right down") {
			DesertMap.renderOrder::right_down;
			LOG("file loaded. Render Order: Right Down");
		}
		else if (RenderValue == "right up") {
			DesertMap.renderOrder::right_up;
			LOG("file loaded. Render Order: Right Up");
		}
		else if (RenderValue == "left down") {
			DesertMap.renderOrder::left_down;
			LOG("file loaded. Render Order: Left Down");
		}
		else if (RenderValue == "left up") {
			DesertMap.renderOrder::left_up;
			LOG("file loaded. Render Order: Left Up");
		}
		else {
			DesertMap.renderOrder::error_render;
			LOG("file loaded. error, couldnt load render order");
		}

	}
	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
	

	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything
	}

	map_loaded = ret;

	return ret;
}

void LoadMap() 
{

}

