#include "controller.hxx"
#include <fstream>
#include <stdexcept>
#include <iostream>

///
/// Constructors
///

Controller::Controller(ge211::Dims<int> screen_dimensions)
        : model_(screen_dimensions),
          view_(model_),
          screen_dimensions_(screen_dimensions)
{
}

///
/// Public member functions
///

ge211::Dims<int>
Controller::initial_window_dimensions() const
{
    return screen_dimensions_;
}

void
Controller::on_key_up(ge211::Key key)
{
    if (key == ge211::Key::left()) {
        model_.go_left_1(false);
    }
    if (key == ge211::Key::right()) {
        model_.go_right_1(false);
    }
    if (key == ge211::Key::up()) {
        model_.go_up_1(false);
    }

    if (key == ge211::Key::down()) {
        model_.go_down_1(false);
    }
    if (key == ge211::Key::shift()) {
        model_.turn_right_1(false);
    }

    if (key == ge211::Key::code('/')) {
        model_.turn_left_1(false);
    }

    if (key == ge211::Key::control()) {
        model_.fire_bullet_1();
    }

    // for player 2
    if (key == ge211::Key::code('a')) {
        model_.go_left_2(false);
    }
    if (key == ge211::Key::code('d')) {
        model_.go_right_2(false);
    }
    if (key == ge211::Key::code('w')) {
        model_.go_up_2(false);
    }

    if (key == ge211::Key::code('s')) {
        model_.go_down_2(false);
    }
    if (key == ge211::Key::code('e')) {
        model_.turn_right_2(false);
    }

    if (key == ge211::Key::code('q')) {
        model_.turn_left_2(false);
    }

    if (key.code() == ' ') {
        model_.fire_bullet_2();
    }

    if (key.code() == 'p') {
        exit(0);
    }



}

void
Controller::on_key_down(ge211::Key key)
{
    if (key == ge211::Key::left()) {
        model_.go_left_1(true);
    }
    if (key == ge211::Key::right()) {
        model_.go_right_1(true);
    }
    if (key == ge211::Key::up()) {
        model_.go_up_1(true);
    }

    if (key == ge211::Key::down()) {
        model_.go_down_1(true);
    }
    if (key == ge211::Key::shift()) {
        model_.turn_right_1(true);
    }

    if (key == ge211::Key::code('/')) {
        model_.turn_left_1(true);
    }

    // for player 2
    if (key == ge211::Key::code('a')) {
        model_.go_left_2(true);
    }
    if (key == ge211::Key::code('d')) {
        model_.go_right_2(true);
    }
    if (key == ge211::Key::code('w')) {
        model_.go_up_2(true);
    }

    if (key == ge211::Key::code('s')) {
        model_.go_down_2(true);
    }
    if (key == ge211::Key::code('e')) {
        model_.turn_right_2(true);
    }

    if (key == ge211::Key::code('q')) {
        model_.turn_left_2(true);
    }
}

void
Controller::on_frame(double dt)
{
    model_.update(dt);
}

void
Controller::draw(ge211::Sprite_set& sprites)
{
    view_.draw(sprites);
}


void
Controller::on_mouse_up(
        ge211::Mouse_button button, ge211::Posn<int>
position)
{
}

