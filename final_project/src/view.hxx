#pragma once
#include <algorithm>
#include "model.hxx"
#include <chrono>

// Controls how the game is shown to the user:
class View
{
public:
    ///
    /// Public member functions
    ///
    explicit View(Model&);

    void draw(ge211::Sprite_set&) const;

private:
    ///
    /// Private helper functions
    ///

    // The view can look at the model but doesn't change it.
    Model& model_;

    // Sprites for tiles:
    ge211::Image_sprite obstacle_ {"obstaclesprite.JPG"};
    ge211::Image_sprite player_ {"player.JPG"};
    ge211::Image_sprite bullet_ {"bullet.JPG"};
    ge211::Circle_sprite const player1_center;
    ge211::Circle_sprite const player2_center;
    ge211::Rectangle_sprite const gun_;
    ge211::Rectangle_sprite const brick1_sprite;
    ge211::Rectangle_sprite const brick2_sprite;
    ge211::Circle_sprite const red_plat;
    ge211::Rectangle_sprite const Background_sprite;
    ge211::Font sans30{"sans.ttf", 30};
    ge211::Text_sprite player1_wins_sprite {"Player 1 wins!!", sans30};
    ge211::Text_sprite player2_wins_sprite {"Player 2 wins!!", sans30};;
    //ge211::Image_sprite gun_ {"torpedo.gif"};

    double obstacle_scale_ = 1;
    double player_scale_ = 0.3;
    double bullet_scale_ = .03;
};
