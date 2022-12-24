#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "field_object.hpp"
#include <vector>
#include <set>

enum class STEP_SNAKE {
	RIGHT = -1,
	LEFT = 1,
	DOWN = -2,
	UP = 2,
};

class Snake {
public:
	Snake(const size_t WIDTH, const size_t HEIGHT);
	bool end_game() const;
	bool wing_game() const;
	Field_Object get_snake_head() const;
	Field_Object get_snake_tail() const;
	const std::vector<Field_Object>& get_snake() const;
    const Field_Object& get_apple() const;
	bool set_step(STEP_SNAKE new_step);
	bool step();
    STEP_SNAKE get_step() const;
	size_t get_gray_apples() const;

private:
	Field_Object _generation_apple() const;
	Field_Object _new_index_snake() const;
	const size_t _WIDTH;
	const size_t _HEIGHT; 
	const size_t _FREE_ELEMENTS;
	STEP_SNAKE _step;
	size_t _gray_apples;
	bool _end_game;

	std::vector<std::vector<TYPE_FIELD_OBJECT> > _data;
	std::vector<Field_Object> _snake;
    Field_Object _apple;
};

#endif
