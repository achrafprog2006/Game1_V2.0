#include"headers/Materials.h"

Material Materials::plastic = Material(glm::vec3(0,0,0), glm::vec3(0.1f,0.35f,0.1f), glm::vec3(0.45f,0.55f,0.45f), 0.25f);
Material Materials::Light1 = Material(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1, 1, 1), glm::vec3(0.5, 0.5,0.5), 0.5);
Material Materials::gold = Material(glm::vec3(0.24725f, 0.1995f, 0.0745f), glm::vec3(0.75164f, 0.60648f, 0.22648f), glm::vec3(0.628281f, 0.555802f, 0.366065f), 0.1f);
//0.0	0.0	0.0	0.1	0.35	0.1	0.45	0.55	0.45	.25
//0.24725	0.1995	0.0745	0.75164	0.60648	0.22648	0.628281	0.555802	0.366065	0.4
