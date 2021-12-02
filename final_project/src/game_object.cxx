
#include"game_object.hxx"
#include <cmath>
#include "model.hxx"
#include <iostream>
#include <chrono>
#include <unistd.h>


//Converts degrees to radians
static double
degrees_to_radian(double degrees)
{
    return acos(-1) * degrees / 180;
}

//Finds the distance between two game objects
static double
distance(Game_object::Position a, Game_object::Position b)
{
    Game_object::Dimensions d = a - b;
    return sqrt(d.width * d.width + d.height * d.height);
}

Game_object::Game_object(Material material, Position position)
        : top_left_(position),
          material_(material)
{

}

//Checks if two game objects collide
bool
Game_object::check_collision(Game_object *go1, Game_object *go2)
{
    if (go1->is_destroyed() || go2->is_destroyed()) { return false; }
    double g1 = go1->size();
    double g2 = go2->size();
    Position p1 = go1->position();
    Position p2 = go2->position();
    if (distance(p1, p2) < (g1 + g2) / 2) {
        if (go1->material() != go2->material()) {
            go1->collide(go2);
            go2->collide(go1);
            return true;
        }

    }
    return false;
}

//Checks if a game object got destroyed
bool
Game_object::is_destroyed()  const
{
    return destroyed_object_;
}

//Returns the material that a game object is made of
Game_object::Material
Game_object::material() const
{
    return material_;
}

//Returns the playerType of a player
Player::Player_type
Player::playerType() const
{
    return playerType_;
}
//Returns the position of a game object
Game_object::Position
Game_object::position() const
{
    return top_left_;
}

//Returns the directions that a player tries to move in
Control&
Player::control()
{
    return control_;
}

void Player::setPlayerType(Player_type p) {
    playerType_ = p;
}

//Constructs a movable game object
Movable_game_object::Movable_game_object(
        Material material,
        Position position,
        Velocity velocity,
        Angular_velocity angular_velocity)
        : Game_object(material, position),
          v_(velocity),
          ddeg_(angular_velocity)

{
}

//Returns the direction in which a game object is heading
Game_object::Angle
Game_object::heading() const
{
    return deg_;
}

void
Game_object::integrate(double dt) {
    return;
}



//Moves a player in time
void
Player::integrate(double dt)
{

    v_= {0,0};

    if (control_.turn_right) {
        deg_ += heading_change * dt;
    }
    if (control_.turn_left) {
        deg_ -= heading_change * dt;
    }
    if (deg_ < 0) { deg_ += 360; }
    if (deg_ > 360) { deg_ -= 360; }

    if(control_.up){
        v_+=
                {sin(degrees_to_radian(0))*velocity_change,
                 -cos(degrees_to_radian(0))*velocity_change};
    }

    if(control_.down){
        v_+=
                {sin(degrees_to_radian(180))*velocity_change,
                 -cos(degrees_to_radian(180))*velocity_change};

    }

    if(control_.right){
        v_+=
                {sin(degrees_to_radian(90))*velocity_change,
                 -cos(degrees_to_radian(90))*velocity_change};
    }

    if(control_.left){
        v_+=
                {sin(degrees_to_radian(270))*velocity_change,
                 -cos(degrees_to_radian(270))*velocity_change};
    }


    double future_x = top_left_.x +v_.width * dt;
    double future_y = top_left_.y + v_.height * dt;




    if (future_x < 0 ||
            future_x > screen_dimensions_.width ||
            future_y < 0 ||
            future_y > screen_dimensions_.height) {
        // find a way to make for integrate to only happen  if  this is not the case when integrate happens
        return;
    }

    if (future_x >= 100 && future_x <= 308 && future_y >= 100 && future_y <=
    306)
    {
        return;
    }
    if (future_x >= 724 && future_x <= 932 && future_y >= 100 && future_y <=
                                                                 306)
    {
        return;
    }
    if (future_x >= 100 && future_x <= 308 && future_y >= 468 && future_y <=
                                                                 679)
    {
        return;
    }
    if (future_x >= 724 && future_x <= 932 && future_y >= 468 && future_y <=
                                                                 674)
    {
        return;
    }
    if (future_x >= 412 && future_x <= 620 && future_y >= 284 && future_y <=
                                                                 490)
    {
        return;
    }


    Movable_game_object::integrate(dt);
}


//Moves a gun in time
void
Gun::integrate(double dt)
{
    top_left_.x=player_->position().x-6+ 60*sin(degrees_to_radian(player_
            ->heading
            ()));
    top_left_.y=player_->position().y-10-60*cos(degrees_to_radian
            (player_->heading
                                                                             ()));
    deg_=player_->heading();
}

//Moves a movable game object
void
Movable_game_object::integrate(double dt)
{
    top_left_.x += v_.width * dt;
    top_left_.y += v_.height * dt;
    v_ += dv_ * dt;
    deg_ += ddeg_ * dt;
}

//Sets the angular velocity of a movable game object
void
Movable_game_object::set_angular_velocity(Angular_velocity vel)
{
    ddeg_ = vel;
}

//Returns the acceleration of a movable game object
Movable_game_object::Acceleration
Movable_game_object::acceleration() const
{
    return dv_;
}

//Creates an obstacle class
Obstacle::Obstacle(
        double mass,
        Position position,
        Position top_left_margin,
        Position bottom_right_margin)
        : Game_object(Game_object::Material::brick,
                      position),
          mass_(mass),
          tl_margin(top_left_margin),
          br_margin(bottom_right_margin)
{
}



//Mass of obstacle
double
Obstacle::mass() const
{
    return mass_;
}

//Class called bullet
//doesn't necessarily need angular velocity
Bullet::Bullet(Position position, Angle heading, Dimensions screen_dimensions)
        : Movable_game_object(Game_object::Material::metal,
                              position,
                              {sin(degrees_to_radian(heading)) *
                               bullet_speed,
                               -cos(degrees_to_radian(heading)) *
                               bullet_speed},
                              1440),
          screen_dimensions_(screen_dimensions)
{
}

//moves a bullet in time
void
Bullet::integrate(double dt)
{
    double future_x = top_left_.x +v_.width * dt;
    double future_y = top_left_.y + v_.height * dt;

    if (future_x >= 100 && future_x <= 308 && future_y >= 100 && future_y <=
                                                                 306)
    {
        destroyed_object_ = true;
        return;
    }
    if (future_x >= 724 && future_x <= 932 && future_y >= 100 && future_y <=
                                                                 306)
    {
        destroyed_object_ = true;
        return;
    }
    if (future_x >= 100 && future_x <= 308 && future_y >= 468 && future_y <=
                                                                 679)
    {
        destroyed_object_ = true;
        return;
    }
    if (future_x >= 724 && future_x <= 932 && future_y >= 468 && future_y <=
                                                                 674)
    {
        destroyed_object_ = true;
        return;
    }
    if (future_x >= 412 && future_x <= 620 && future_y >= 284 && future_y <=
                                                                 490)
    {
        destroyed_object_ = true;
        return;
    }

    Movable_game_object::integrate(dt);
    if (top_left_.x < 0 ||
        top_left_.x > screen_dimensions_.width ||
        top_left_.y < 0 ||
        top_left_.y > screen_dimensions_.height) {
        destroyed_object_ = true;
    }
}

//Pixel size of a player
double
Player::size()
{
    return 60;
}

//Pixel size of an object
double
Obstacle::size()
{
    return 80;
}

double
Gun::size() {
    return 30;
}

//Pixel size of a bullet
double
Bullet::size()
{
    return 8;
}

// If an obstacle collides with anything
//But will likely not do anything
void
Obstacle::collide(Game_object const *other)
{

}

void
Player::disintegrate()
{
    top_left_.x -= v_.width * 2;
    top_left_.y -= v_.height * 2;
}

std::vector<Block>
Player::playerBricks()
{
    return bricks;
}

void
Player::reduce_life()
{
    bricks.pop_back();

}

void
Player::add_bricks(Block brick)
{
    bricks.push_back(brick);
}

// If a player collides with a game object
void
Player::collide(Game_object const *other)
{
   /* if (other->material() == Material::brick) {
        disintegrate();
    }*/
    if (other->material() == Material::metal) {
        life_left-= 1;
        std::cout<< life_left << "\n";
        set_pain(true);
        start = std::chrono::steady_clock::now();

        //have to do sth here. Red splat
        reduce_life();
        if(life_left==0){
            //have to do sth here. Set winner to other player since player is
            // enum class
            //winner could be initially neither.
            //could have a new enum class that stores player 1, player 2 and
            // neither
            destroyed_object_=true;
        }
    }

}

//If a bullet collides with a game object
void
Bullet::collide(Game_object const *other)
{
    if (other->material() != Material::metal && other->material() !=
    Material::gun) {
        destroyed_object_ = true;
    }
}

void
Gun::collide(Game_object const *other)
{

}

bool
Player::get_pain()
{
    return pain_;
}

void
Player::set_pain(bool b)
{
    pain_ = b;
}



