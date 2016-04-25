#include "Random.h"

#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

namespace util
{
	default_random_engine engine((default_random_engine::result_type)system_clock::now().time_since_epoch().count());
	uniform_int_distribution<> int_dist;
	uniform_real_distribution<> double_dist;
	typedef uniform_int_distribution<>::param_type int_param;
	typedef uniform_real_distribution<>::param_type real_param;

	int random_int()
	{
		return int_dist(engine);
	}

	int random_int(int a, int b)
	{
		return int_dist(engine, int_param(a, b));
	}

	double random_double()
	{
		return double_dist(engine);
	}

	double random_double(double a, double b)
	{
		return double_dist(engine, real_param(a, b));
	}
};
