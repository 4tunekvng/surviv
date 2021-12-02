#include "model.hxx"
#include"model.hxx"

double const initial_asteroid_mass = 1;
double const min_asteroid_mass = 0.1;



///
/// Constructors
///
Model::Model(ge211::Dims<int> screen_dimensions)
        : screen_dimensions_(screen_dimensions),
          player_1(screen_dimensions_.into<double>()),
          player_2(screen_dimensions_.into<double>()),
          random_x_coor_(0, screen_dimensions_.width),
          random_y_coor_(0, screen_dimensions_.height),
          random_velocity_(-5, 5),
          random_angular_velocity_(10, 100),
          gun1(screen_dimensions_.into<double>(),&player_1),
          gun2(screen_dimensions_.into<double>(), &player_2)
{
    // use .stub_with(...) here on random sources if you want non-random
    // results while developing

    player_1.top_left_.x= 974;
    player_1.top_left_.y= 693;
    player_1.setPlayerType(Player::Player_type::player_1);
    player_2.setPlayerType(Player::Player_type::player_2);

    game_objects_.emplace_back(&player_1);
    game_objects_.emplace_back(&player_2);
    game_objects_.emplace_back(&gun1);
    game_objects_.emplace_back(&gun2);
    /*for (int i = 0; i < 5; i++) {
        new_obstacle_(initial_asteroid_mass, {-1, -1});
    }*/
    new_obstacle_(initial_asteroid_mass, {100, 100});
    new_obstacle_(initial_asteroid_mass, {724, 100});
    new_obstacle_(initial_asteroid_mass, {100, 468});
    new_obstacle_(initial_asteroid_mass, {412, 284});
    new_obstacle_(initial_asteroid_mass, {724,468 });

    int player1_life_side_margin = 1000;
    int player1_life_top_margin = 350;

    int player2_life_side_margin = 5;
    int player2_life_top_margin = 350;

    int brick_width = 20;
    int brick_height = 5;

   // int x_offset = brick_width;
   // int y_offset = brick_height;

    //int curr_x = player1_life_side_margin;

    int curr_y1 = player1_life_top_margin;
    int curr_y2 = player2_life_top_margin;


    for (int col = 0; col < 1; col++)
    {
       for  (int row = 0; row < 20; row++)
       {
           Block brick = {player1_life_side_margin, curr_y1, brick_width,
                          brick_height};
           player_1.add_bricks(brick);
           curr_y1 = curr_y1 + brick_height;
       }
    }

    for (int col = 0; col < 1; col++)
    {
        for  (int row = 0; row < 20; row++)
        {
            Block brick = {player2_life_side_margin, curr_y2, brick_width,
                           brick_height};
            player_2.add_bricks(brick);
            curr_y2 = curr_y2 + brick_height;
        }
    }
}

///
/// Public member functions
///

void
Model::new_obstacle_(double mass, Game_object::Position pos)
{


    game_objects_.push_back(
            std::make_unique<Obstacle>(
                    mass,
                    pos,
                    Game_object::Position {0, 0},
                    Game_object::Position {
                            (double) screen_dimensions_.width ,
                            (double) screen_dimensions_.height}));
}

void
Model::update(double ft)
{


    for (std::unique_ptr<Game_object>& go : game_objects_) {
        go->integrate(ft);
    }
    for (std::size_t i = 0; i < game_objects_.size(); i++) {
        for (std::size_t j = i + 1; j < game_objects_.size(); j++) {
            Game_object *so1 = game_objects_[i].get();
            Game_object *so2 = game_objects_[j].get();

            if (Game_object::check_collision(so1, so2)) {

            }
        }
    }






    /*if (player_1.is_destroyed()||player_2.is_destroyed()) {
        exit(1);
    }*/
}

void
Model::turn_right_1(bool state)
{
    player_1.control().turn_right = state;
}

void
Model::turn_left_1(bool state)
{
    player_1.control().turn_left = state;
}

void
Model::go_up_1(bool state)
{
    player_1.control().up = state;
}

void
Model::go_down_1(bool state)
{
    player_1.control().down = state;
}

void
Model::go_left_1(bool state)
{
    player_1.control().left = state;
}

void
Model::go_right_1(bool state)
{
    player_1.control().right = state;
}

void
Model::fire_bullet_1()
{
    game_objects_.emplace_back(new Bullet(gun1.position(),
                                            player_1.heading(),
                                            screen_dimensions_.into<double>()));
}

void
Model::turn_right_2(bool state)
{
    player_2.control().turn_right = state;
}

void
Model::turn_left_2(bool state)
{
    player_2.control().turn_left = state;
}

void
Model::go_up_2(bool state)
{
    player_2.control().up = state;
}

void
Model::go_down_2(bool state)
{
    player_2.control().down = state;
}

void
Model::go_left_2(bool state)
{
    player_2.control().left = state;
}

void
Model::go_right_2(bool state)
{
    player_2.control().right = state;
}


void
Model::fire_bullet_2()
{
    game_objects_.emplace_back(new Bullet(gun2.position(),
                                          player_2.heading(),
                                          screen_dimensions_.into<double>()));
}

std::vector<std::unique_ptr<Game_object>>&
Model::game_objects()
{
    return game_objects_;
}

Player
Model::get_player1()
{
    return player_1;
}

Player
Model::get_player2()
{
    return player_2;
}

///
/// Private member functions
///
