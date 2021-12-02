

//
// Created by fortu on 11/21/2021.
//

#pragma once

#include<memory>
#include <ge211.hxx>
#include<iostream>
#include <chrono>
#include <unistd.h>


using Block = ge211::Rect<int>;


struct Control
{
    bool left = false;
    bool right = false;
    bool up = false;
    bool down= false;
    bool turn_right = false;
    bool turn_left = false;
};

class Game_object
{
public:
    static bool check_collision(Game_object *go1, Game_object *go2);

    using Dimensions = ge211::Dims<double>;
    using Position = ge211::Posn <double>;
    using Angle = double; // in ° counterclockwise from N


    enum class Material
    {
        flesh,    // the player
        metal,  // the bullet
        brick,    // the obstacles
        gun,
    };

    Game_object(Material, Position);

    bool is_destroyed() const;

    Material material() const;

    Position position() const;

    Angle heading() const;

    virtual double size() = 0;

    virtual void integrate(double dt);

    // Object just dies by default; override to survive, delegate to die.
    virtual void collide(Game_object const *other)
    {
        destroyed_object_= true;
    }

    // Facing direction, may not match velocity
    virtual ~Game_object() = default;

    Position top_left_;
protected:
    Angle deg_ = 0.0;
    bool destroyed_object_= false;
private:
    Material material_;
};


class Movable_game_object : public Game_object
{
public:
    using Angle = double; // in ° counterclockwise from N
    using Velocity = ge211::Dims<double>;
    using Acceleration = ge211::Dims<double>;
    using Angular_velocity = double;


    Movable_game_object(
            Material,
            Position,
            Velocity = {0.0, 0.0},
            Angular_velocity = 0.0);

    void integrate(double dt) override;

protected:
    Acceleration acceleration() const;

    // Currently rotation control is instantaneous rather than
    // mediated by angular acceleration.
    void set_angular_velocity(Angular_velocity vel);

    Velocity v_ = {0, 0};


private:
    Acceleration dv_ {0.0, 0.0};
    Angular_velocity ddeg_ = 0;
};


class Player : public Movable_game_object
{
public:
    explicit Player(Dimensions screen_dimensions)
            : Movable_game_object(Game_object::Material::flesh,
                                    {50,
                                     75}),
              screen_dimensions_(screen_dimensions)

    { }

    std::chrono::time_point<std::chrono::steady_clock> start;
    std::chrono::time_point<std::chrono::steady_clock> end;
    enum class Player_type
            {
        player_1,
        player_2,
            };

    // Facing direction, may not match velocity
    Control& control();

    void rotate();

    Player_type playerType() const;

    void setPlayerType(Player_type p);

    bool alive();

    void integrate(double dt) override;

    void disintegrate();

    double size() override;

    void collide(Game_object const *other) override;

    void reduce_life();

    std::vector<Block> playerBricks();

    void add_bricks(Block brick);

    bool get_pain();

    void set_pain(bool b);

private:
    double const heading_change = 180;
    double const velocity_change = 200;
    Control control_ {false, false, false};
    Dimensions screen_dimensions_;
    int life_left = 20;
    Player_type playerType_;
    std::vector<Block> bricks;
    bool pain_ = false;

};

class Obstacle : public Game_object
{
public:
    Obstacle(
            double mass,
            Position position,
            Position top_left_margin,
            Position bottom_right_margin);

    //void integrate(double dt) override;

    double mass() const;

    double size() override;

    void collide(Game_object const *other) override;

private:
    double mass_;
    Position tl_margin;
    Position br_margin;
    std::string shape;
};


double const bullet_speed = 1000.0;

class Bullet : public Movable_game_object
{
public:
    Bullet(Position position, Angle heading, Dimensions screen_dimensions);

    void integrate(double dt) override;

    double size() override;

    void collide(Game_object const *other) override;

private:
    Dimensions screen_dimensions_;

};


class Gun : public Movable_game_object
{
public:
    explicit Gun(Dimensions screen_dimensions, Player* player)
            : Movable_game_object(Game_object::Material::gun,
                                  {50,
                                   75}),
              screen_dimensions_(screen_dimensions),
              player_(player)
    { }

    enum class Gun_type
    {
        gun_1,
        gun_2,
    };

    // Facing direction, may not match velocity
    Control& control();

    void rotate();

    Gun_type gunType() const;

    void setGunType(Gun_type p);

    bool alive();

    void integrate(double dt) override;

    void disintegrate();

    double size() override;

    void collide(Game_object const *other) override;

private:
    double const heading_change = 180;
    double const velocity_change = 200;
    Control control_ {false, false, false};
    Dimensions screen_dimensions_;
    int life_left=10;
    Gun_type gunType_;
    Player* player_;
};


