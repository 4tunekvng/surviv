#pragma once
#include "game_object.hxx"
#include<memory>
#include<algorithm>
#include<iostream>
#include <ge211.hxx>


class Model
{
public:

    static int const max_mass = 5;
    static int const bullet_length = 10;
    static int const obstacle_length = 40;

    ///
    /// Constructors
    ///
    // Uses the dimensions of the board
    Model(ge211::Dims<int> screen_dimensions);

    ///
    /// Public member functions
    ///
    std::vector<std::unique_ptr<Game_object>>& game_objects();
    void update(double ft);
    void control_players(Control control);
    void fire_bullet_1();
    void fire_bullet_2();
    Control& control();
    void turn_right_1(bool state);
    void turn_left_1(bool state);
    void go_up_1(bool state);
    void go_down_1(bool state);
    void go_left_1(bool state);
    void go_right_1(bool state);

    void turn_right_2(bool state);
    void turn_left_2(bool state);
    void go_up_2(bool state);
    void go_down_2(bool state);
    void go_left_2(bool state);
    void go_right_2(bool state);

    Player get_player1();
    Player get_player2();


private:

    ///
    /// Private helper functions
    ///
    void new_obstacle_(double mass, Game_object::Position);

    ///
    /// Private member variables
    ///
    std::vector<std::unique_ptr<Game_object>> game_objects_;
    ge211::Dims<int> screen_dimensions_;
    int obstacle_max_mass_;
    Player player_1;
    Player player_2;
    Gun gun1;
    Gun gun2;


    Control control_;

    // Random sources
    ge211::Random_source<int> random_x_coor_;
    ge211::Random_source<int> random_y_coor_;
    ge211::Random_source<int> random_velocity_;
    ge211::Random_source<int> random_angular_velocity_;

};
