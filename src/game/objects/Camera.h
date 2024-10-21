

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {

private:
	float* yaw, * pitch, * roll;
	bool shouldUpdate;

public :
	Camera();
	glm::vec3* position;
	glm::mat4 view;
	glm::mat4 getViewMatrix();
	void increasePosition(float dx, float dy, float dz);
	void increasePitch(float dp);
	void increaseYaw(float dy);

	~Camera();



};