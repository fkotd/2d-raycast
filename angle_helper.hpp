#include <cmath>

inline float degree_to_radian(float degree) {
	return degree * M_PI * 180; 
}

inline float radian_to_degree(float radian) {
	return radian * 180 / M_PI;
}
