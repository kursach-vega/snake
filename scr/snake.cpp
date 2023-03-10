#include "../headers/snake.hpp"
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <iostream>

Field_Object Snake::_generation_apple() const {
    size_t score_free_electrons = this->_FREE_ELEMENTS;
    score_free_electrons -= this->_snake.size();
    std::cout << score_free_electrons << std::endl;
	if ( score_free_electrons == 0 ) {
		return Field_Object(-1, -1, TYPE_FIELD_OBJECT::NONE);
	}
	size_t new_apple = std::rand() % score_free_electrons ;
    for (ptrdiff_t i = 0; i < this->_HEIGHT; i++) {
        for (ptrdiff_t j = 0; j < this->_WIDTH; j++) {
			new_apple -= (this->_data[i][j] == 
					       TYPE_FIELD_OBJECT::NONE ? 1 : 0);
			if ( !new_apple ) {
				return Field_Object(i, j, TYPE_FIELD_OBJECT::APPLE);
			}
		}
	}
	return Field_Object(-1, -1, TYPE_FIELD_OBJECT::NONE);
}

Field_Object Snake::_new_index_snake() const {
	Field_Object new_index = this->get_snake_head();
	switch ( this->_step ) {
		case STEP_SNAKE::LEFT :
			new_index.x -= 1;
			break;
		case STEP_SNAKE::RIGHT:
			new_index.x += 1;
			break;
		case STEP_SNAKE::DOWN:
			new_index.y += 1;
			break;
		case STEP_SNAKE::UP:
			new_index.y -= 1;
			break;
		default:
			return Field_Object(-1, -1, new_index.type);
	}
    new_index.x = (new_index.x % this->_WIDTH + this->_WIDTH) % this->_WIDTH;
    new_index.y = (new_index.y % this->_HEIGHT + this->_HEIGHT) % this->_HEIGHT;
	return new_index;
}

Snake::Snake(const size_t HEIGHT, const size_t WIDTH) : _WIDTH(WIDTH),
    _HEIGHT(HEIGHT), _FREE_ELEMENTS(WIDTH * HEIGHT), _step(STEP_SNAKE::RIGHT),
    _gray_apples(0), _end_game(false),
    _data(HEIGHT, (std::vector<TYPE_FIELD_OBJECT> (WIDTH,
                                         TYPE_FIELD_OBJECT::NONE))) {
    std::srand(std::time(nullptr));
    this->_data[1][0] = TYPE_FIELD_OBJECT::SNAKE;
	this->_data[1][1] = TYPE_FIELD_OBJECT::SNAKE;
    this->_snake.push_back(make_Field_Object(1, 0, TYPE_FIELD_OBJECT::SNAKE));
    this->_snake.push_back(make_Field_Object(1, 1, TYPE_FIELD_OBJECT::SNAKE));
    this->_turns.push_back(this->_step);
    this->_turns.push_back(this->_step);
	Field_Object new_apple = this->_generation_apple();
	this->_data[new_apple.y][new_apple.x] = TYPE_FIELD_OBJECT::APPLE;
    this->_apple = new_apple;
	return ;
}

bool Snake::end_game() const {
	return this->_end_game;
}

bool Snake::wing_game() const {
    return this->_snake.size() == this->_FREE_ELEMENTS;
}

Field_Object Snake::get_snake_head() const {
    return *(this->_snake.end() - 1);
}

Field_Object Snake::get_snake_tail() const {
    return *(this->_snake.begin());
}

const std::vector<Field_Object>& Snake::get_snake() const {
	return this->_snake;
}

const Field_Object& Snake::get_apple() const {
	return this->_apple;
}

bool Snake::set_step(STEP_SNAKE new_step) {
	short step_difference = static_cast<short>(this->_step);
    step_difference += static_cast<short>(new_step);
	if ( step_difference ) {
		this->_step = new_step;
		return true;
	}
	return false;
}

bool Snake::step() {
	Field_Object new_index = this->_new_index_snake();
	Field_Object snake_tail = this->get_snake_tail();
	this->_data[snake_tail.y][snake_tail.x] = TYPE_FIELD_OBJECT::NONE;
        switch ( this->_data[new_index.y][new_index.x] ) {
		case TYPE_FIELD_OBJECT::SNAKE : {
			this->_end_game = true;
			this->_data[snake_tail.y][snake_tail.x] = snake_tail.type; 
			break;
		}
		case TYPE_FIELD_OBJECT::APPLE : {
	                this->_turns.push_back(this->_step);
			this->_data[snake_tail.y][snake_tail.x] = snake_tail.type; 
			this->_gray_apples += 1;
		 	this->_snake.push_back(new_index);
            Field_Object new_index_apple = this->_generation_apple();
			this->_data[new_index.y][new_index.x] = new_index.type;
			if ( new_index_apple.x == -1 ) {
                std::cout << "arrr" << std::endl;
                this->_end_game = false;
				break;
			}
            this->_apple = new_index_apple;
			this->_data[new_index_apple.y][new_index_apple.x] = 
								 new_index_apple.type;
			break;
		}
		case TYPE_FIELD_OBJECT::NONE : {
	            this->_turns.push_back(this->_step);
            	    this->_turns.pop_front();
		    this->_data[snake_tail.y][snake_tail.x] = TYPE_FIELD_OBJECT::NONE;
            	    this->_snake.erase(this->_snake.begin());
		    this->_snake.push_back(new_index);
		    this->_data[new_index.y][new_index.x] = new_index.type;
		    break;
	       }
    }
    return this->_end_game;
}

STEP_SNAKE Snake::get_step() const {
    return this->_step;
}

const std::deque<STEP_SNAKE> &Snake::get_turns() const {
    return this->_turns;
}

size_t Snake::get_gray_apples() const {
	return this->_gray_apples;
}
