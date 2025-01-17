#pragma once
#define MAX_LIGHTS 20
#include <GL/glew.h>
#include <Transform.h>
#include <glm/glm.hpp>
#include <GameObject.h>
namespace aw
{
	enum LightType
	{
		DIRECTIONAL,
		POINT,
		SPOT
	};

	class Light
	{
	private:
		struct LightStruct
		{
			int enabled;
			LightType type;
			float padding0,padding1;
			glm::vec4 ambient, diffuse, specular;
			glm::vec3 direction;
			float angle;
			glm::vec3 position;
			float padding2;
		} lightStruct;

		GameObject *parent = nullptr;
		int index;

		static GLuint UBO;

	public:
		Transform transform;
		Light(glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, LightType type,
			  glm::vec3 position, glm::vec3 direction, float angle, GameObject *parent = nullptr);
		~Light();
		void setAmbient(glm::vec4 ambient);
		void setDiffuse(glm::vec4 diffuse);
		void setSpecular(glm::vec4 specular);
		void setAngle(float angle);
		void update();
		void toggle();

		static void constructUniformBuffer(std::vector<Light> &lights);
	};
}