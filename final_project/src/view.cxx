#include "view.hxx"
#include "game_object.hxx"
#include <iostream>
#include <chrono>

///
/// Constructor
///
static ge211::Color const player1_center_color {0, 0, 255};
static ge211::Color const player2_center_color {0, 255, 0};
static ge211::Color const gun_color {47, 79, 79};
static ge211::Color const brick1_color {0, 0, 255};
static ge211::Color const brick2_color {0, 255, 0};
static ge211::Color const red_splat_color {255, 0, 0};
static ge211::Color const Background_sprite_color {0, 0, 0};


View::View(Model& model)
        : model_(model),
          player1_center(8,player1_center_color),
          player2_center(8,player2_center_color),
          gun_({30,100},gun_color),
          brick1_sprite({20,4},brick1_color),
          brick2_sprite({20,4},brick2_color),
          red_plat(8, red_splat_color),
          Background_sprite({1024,768}, Background_sprite_color)
{}

///
/// Member functions
///

void
View::draw(ge211::Sprite_set& sprites) const
{
    for (Block brick : model_.get_player1().playerBricks())
    {
        sprites.add_sprite(brick1_sprite, brick.top_left());
    }

    for (Block brick : model_.get_player2().playerBricks())
    {
        sprites.add_sprite(brick2_sprite, brick.top_left());
    }

    std::vector<std::unique_ptr<Game_object>>
            & space_objects = model_.game_objects();
    for (std::unique_ptr<Game_object>& so : space_objects) {
        if (!so->is_destroyed()) {
            ge211::Posn<int> pos {0, 0};
            pos.x = (int) so->position().x;
            pos.y = (int) so->position().y;
            ge211::Transform
                    rotation = ge211::Transform::rotation(so->heading());
            switch (so->material()) {
                case Game_object::Material::flesh: // spaceship
                    rotation.set_scale(player_scale_);
                    pos.x -= player_.dimensions().width * player_scale_ / 2;
                    pos.y
                            -=
                            player_.dimensions().height * player_scale_ / 2;
                    sprites.add_sprite(player_, pos, 2, rotation);
                    if (((std::unique_ptr<Player>&) so)->playerType()
                    ==Player::Player_type::player_1){
                          sprites.add_sprite(player1_center,{pos.x+34,pos.y
                          + 28
                          },3
                          )  ;
                        //do sth here
                        //if player.get_pain() = true
                        if (((std::unique_ptr<Player>&) so)->get_pain()){
                            sprites.add_sprite(red_plat,{pos.x+34,pos.y
                                                                        + 28
                                               },4
                            )  ;
                            ((std::unique_ptr<Player>&) so)
                                    ->end=std::chrono::steady_clock::now();
                            std::chrono::duration<double> elapsed_seconds = ((std::unique_ptr<Player>&) so)
                                                                                    ->end-((std::unique_ptr<Player>&) so)
                                                                                    ->start;

                            if (elapsed_seconds.count()>0.5){
                                ((std::unique_ptr<Player>&) so)->set_pain
                                                                       (false);
                            }


                        }

                        /*if (((std::unique_ptr<Player>&) so)->is_destroyed())
                        {
                            sprites.add_sprite(Background_sprite,{0,0},5);
                            sprites.add_sprite(player1_center,{512,384},6);
                        }*/
                        //add red spalt
                        //set pain() = false
                    }
                    if (((std::unique_ptr<Player>&) so)->playerType()
                    ==Player::Player_type::player_2){
                        sprites.add_sprite(player2_center,{pos.x+34,pos.y
                                                                     + 28},3
                        )  ;
                        if (((std::unique_ptr<Player>&) so)->get_pain()){
                            sprites.add_sprite(red_plat,{pos.x+34,pos.y
                                                                        + 28
                                               },4
                            )  ;
                            ((std::unique_ptr<Player>&) so)
                            ->end=std::chrono::steady_clock::now();
                            std::chrono::duration<double> elapsed_seconds = ((std::unique_ptr<Player>&) so)
                                                                                    ->end-((std::unique_ptr<Player>&) so)
                                    ->start;

                            if (elapsed_seconds.count()>0.5){
                                ((std::unique_ptr<Player>&) so)->set_pain
                                (false);
                            }

                        }
                        /*if (((std::unique_ptr<Player>&) so)->is_destroyed())
                        {
                            sprites.add_sprite(Background_sprite,{0,0},5);
                            sprites.add_sprite(player2_center,{512,384},6);
                        }*/
                    }



                    break;
                case Game_object::Material::brick: // asteroid
                {
                    Obstacle *ss = dynamic_cast<Obstacle *> (so.get());
                    rotation.set_scale(obstacle_scale_ * ss->mass());
                    /*pos.x
                            -=
                            obstacle_.dimensions().width * obstacle_scale_ *
                            ss->mass() / 2;
                    pos.y
                            -=
                            obstacle_.dimensions().height * obstacle_scale_ *
                            ss->mass() / 2;*/
                    sprites.add_sprite(obstacle_, pos, 0, rotation);
                }
                    break;
                case Game_object::Material::gun: // spaceship
                    rotation.set_scale(player_scale_);
                    /*pos.x -= gun_.dimensions().width * player_scale_ / 2;
                    pos.y
                        -=
                        gun_.dimensions().height * player_scale_ / 2;*/
                    sprites.add_sprite(gun_, pos, 2, rotation);
                    break;
                case Game_object::Material::metal: // light
                    rotation.set_scale(bullet_scale_);
                    pos.x -= bullet_.dimensions().width * bullet_scale_ / 2;
                    pos.y -= bullet_.dimensions().height * bullet_scale_/ 2;
                    sprites.add_sprite(bullet_, pos, 1, rotation);
                    break;


            }
        }

        else{
            ge211::Posn<int> pos {0, 0};
            switch (so->material()) {
                case Game_object::Material::flesh:
                    if (((std::unique_ptr<Player>&) so)->playerType()
                        ==Player::Player_type::player_1){

                        sprites.add_sprite(Background_sprite,{0,0},5);
                        sprites.add_sprite(player_, {382,270}, 6);
                        sprites.add_sprite(player2_center,{512,384},7);
                        sprites.add_sprite(player2_wins_sprite, {412,600}, 8);
                    }
                    if (((std::unique_ptr<Player>&) so)->playerType()
                    ==Player::Player_type::player_2){

                        sprites.add_sprite(Background_sprite,{0,0},5);
                        sprites.add_sprite(player_, {382,270}, 6);
                        sprites.add_sprite(player1_center,{512,384},7);
                        sprites.add_sprite(player1_wins_sprite, {412,600}, 8);
                    }

                break;

            }
        }

    }
}
