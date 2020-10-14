#pragma once
#include <memory>
namespace ge
{
    enum class eItemId //파일로 내보내기
    {
        eEmpty = 0,
        eItem1,
        eItem2,

    };
    enum class eItemType
    {
        eEtc = 0,
        eUse,
        eEquip,
    };
}

struct ItemState
{
    ge::eItemId Id = ge::eItemId::eEmpty;
    ge::eItemType Type = ge::eItemType::eEtc;

    int Str = 0;
    int Dex = 0;
    int Con = 0;
    int Int = 0;
    int Wis = 0;
    int Cha = 0;
    int Atk = 0;
    int Def = 0;
    int Hp = 0;
    int Mp = 0;

    ItemState() {};
    ItemState(ge::eItemId itemId, ge::eItemType key,
              int str, int dex, int con, int _int, int wis, int cha, int atk, int def, int hp, int mp)
    {
        Id = itemId;
        Type = key;
        Str = str;
        Dex = dex;
        Con = con;
        Int = _int;
        Wis = wis;
        Cha = cha;
        Atk = atk;
        Def = def;
        Hp = hp;
        Mp = mp;
        
    }
    bool isEmpty()
    {
        if (Id== ge::eItemId::eEmpty)
        {
            return true;
        }
        return false;
    }
};



class ItemHelper//스크립트로 빼서 사용할 부분, 하드코딩 클래스.
{
public:
  static ItemState getState(ge::eItemId itemId)
  {

      ItemState State;
        switch (itemId)
        {
        case ge::eItemId::eEmpty:
            State = ItemState(itemId, ge::eItemType::eEtc, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            break;
        case ge::eItemId::eItem1:
            State = ItemState(itemId, ge::eItemType::eUse, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
            break;
        case ge::eItemId::eItem2:
            State = ItemState(itemId, ge::eItemType::eEquip, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100);
            break;
        default://에러 처리 하기.
            State = ItemState(itemId, ge::eItemType::eEtc, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            break;
        }
        return State;
  }
};

//
class BaseItem
{
private:
    ItemState State;

public:
    ge::eItemId     getID()                 { return State.Id; };
    void            setID(ge::eItemId id)   { State.Id = id; };
    ItemState getState() { return State; };
    virtual bool process() { return false; };
    //virtual BaseItem&& Create() {};
};

class EquipItem :public BaseItem
{
    bool process();
    //BaseItem&&  Create() override;
};

class UseItem :public BaseItem
{
    bool process();
    //BaseItem&&  Create() override;
};

class EtcItem :public BaseItem
{
    bool process();
    //BaseItem&&  Create() override;
};