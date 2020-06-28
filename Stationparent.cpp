#include "Stationparent.h"

int Stationparent::GetX() const{
    return sx;
} //获取横坐标

int Stationparent::GetY() const{
    return sy;
} //获取纵坐标

int Stationparent::GetWidth() const{
    return width;
} //获取宽度

int Stationparent::GetHeight() const{
    return height;
} //获取高度

int Stationparent::GetAngle() const{
    return Angle;
} //获取角度

int Stationparent::GetAttack() const{
    return Attack;
}

int Stationparent::GetRange() const{
    return Range;
} //获取防御站射程

int Stationparent::GetUpLeftX() const{
    return UpLeftX;
} //获取防御站原位置左上角横坐标

int Stationparent::GetUpLeftY() const{
    return UpLeftY;
} //获取防御站原位置左上角纵坐标

int Stationparent::GetExplRangeWidth() const{
    return ExplRangeWidth;
} //获取爆炸效果宽度

int Stationparent::GetExplRangeHeight() const{
    return ExplRangeHeight;
} //获取爆炸效果高度

int Stationparent::GetBulletWidth() const{
    return Bullwidth;
} //获取子弹宽度

int Stationparent::GetBulletHeight() const{
    return Bullheight;
} //获取子弹高度

int& Stationparent::SetRange(){
    return Range;
} //设置防御战攻击范围

void Stationparent::SetXY(int x, int y){
    this->sx=x; this->sy=y;
} //设置防御站坐标

void Stationparent::SetAngle(int ang){
    Angle=ang;
} //设置防御站旋转角度

void Stationparent::SetAttack(int at){
    this->Attack=at;
} //设置防御站威力

void Stationparent::SetGoalEnemy(Enemy *en){
   goal=en;
} //设置当前防御站的目标敌人

void Stationparent::SetWidthHeight(int width, int height){
    this->width=width;this->height=height;
} //设置防御战高度宽度

void Stationparent::SetBulletWidthHeight(int width, int height){
    Bullwidth=width;Bullheight=height;
} //设置子弹高度宽度

void Stationparent::SetExplRangeWidthHeight(int exwidth, int exheight){
    ExplRangeWidth=exwidth;ExplRangeHeight=exheight;
} //设置爆炸效果高度宽度

void Stationparent::NewBullet(){ //生产子弹函数
    Counter++;
    if(Counter<7 && goal!=0) return; //计数器达到一定数值+目标敌舰不为空
    Bullet*bullet=new Bullet(d(UpLeftX+40,UpLeftY+40)); //插入子弹
    bullet->dd.x=UpLeftX+40,bullet->dd.y=UpLeftY+40;
    if((!(goal->GetX()-bullet->dd.x))){
        delete  bullet;
        bullet =NULL;
        goto Occasion;
    }
    bullet->p=(goal->GetY()-bullet->dd.y)/(goal->GetX()-bullet->dd.x);
    bullet->q=goal->GetY()-goal->GetX()*bullet->p;
    bullet->dd.x=UpLeftX+40;
    bullet->dd.y=UpLeftY+40;
    BulletVec.push_back(bullet); //把子弹放入数组中
    if(goal->GetX()<=UpLeftX+40) bullet->direction=true; //判断子弹运动方向是否正确
    Occasion:
    Counter=0; //重置计数器
}

void Stationparent::BulletMove(){ //子弹移动函数
    for(auto bul:BulletVec){
        const int speed=30; //子弹移动速度
        bul->direction?bul->dd.x-=speed:bul->dd.x+=speed;
        bul->dd.y=bul->p*bul->dd.x+bul->q; //根据子弹移动方向改变子弹坐标
      }
    for(auto bul=BulletVec.begin();bul!=BulletVec.end();bul++)
        if((*bul)->dd.x>1040 || (*bul)->dd.x<0 || (*bul)->dd.y>640 || (*bul)->dd.y<0){
            delete bul;
            BulletVec.erase(bul);
            break;
        } //遍历，删除越界子弹
}

Enemy*Stationparent::GetGoalsEnemy() const{
    return goal;
}

QString Stationparent::GetBaseImgPath() const{
    return BaseImgPath;
} //获取防御站底座图片路径

QString Stationparent::GetDefImgPath() const{
    return DefImgPath;
} //获取防御站图片路径

QString Stationparent::GetBulletPath() const{
    return BullPath;
} //获取子弹图片路径

QVector<Bullet*>& Stationparent::GetBulletVec(){
    return BulletVec;
} //返回子弹数组
