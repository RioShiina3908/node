#pragma once
#include <v8.h>

struct Arbiter {};

struct World {
  virtual void setNpcMaxHp(int huntingZoneId,
                           int templateId,
                           int64_t maxHp) = 0;
  virtual void resetNpcMaxHp(int huntingZoneId, int templateId) = 0;
  virtual void setNpcLevel(int huntingZoneId, int templateId, int level) = 0;
  virtual void resetNpcLevel(int huntingZoneId, int templateId) = 0;
  virtual void setNpcWalkSpeed(int huntingZoneId,
                               int templateId,
                               int walkSpeed) = 0;
  virtual void resetNpcWalkSpeed(int huntingZoneId, int templateId) = 0;
  virtual void setNpcRunSpeed(int huntingZoneId,
                              int templateId,
                              int runSpeed) = 0;
  virtual void resetNpcRunSpeed(int huntingZoneId, int templateId) = 0;
  virtual void setNpcAtk(int huntingZoneId, int templateId, int atk) = 0;
  virtual void resetNpcAtk(int huntingZoneId, int templateId) = 0;
  virtual void setNpcDef(int huntingZoneId, int templateId, int def) = 0;
  virtual void resetNpcDef(int huntingZoneId, int templateId) = 0;
  virtual void setNpcPhysicalAttack(int huntingZoneId,
                                    int templateId,
                                    int physicalAttack) = 0;
  virtual void resetNpcPhysicalAttack(int huntingZoneId, int templateId) = 0;
  virtual void setNpcMagicalAttack(int huntingZoneId,
                                   int templateId,
                                   int magicalAttack) = 0;
  virtual void resetNpcMagicalAttack(int huntingZoneId, int templateId) = 0;
  virtual void setNpcPhysicalDefence(int huntingZoneId,
                                     int templateId,
                                     int physicalDefence) = 0;
  virtual void resetNpcPhysicalDefence(int huntingZoneId, int templateId) = 0;
  virtual void setNpcMagicalDefence(int huntingZoneId,
                                    int templateId,
                                    int magicalDefence) = 0;
  virtual void resetNpcMagicalDefence(int huntingZoneId, int templateId) = 0;
  virtual void setNpcIgnorePhysicalDefence(int huntingZoneId,
                                           int templateId,
                                           int ignorePhysicalDefence) = 0;
  virtual void resetNpcIgnorePhysicalDefnece(int huntingZoneId,
                                             int templateId) = 0;
};

struct Native {
  virtual void run() = 0;
  virtual Arbiter* arbiter() = 0;
  virtual World* world() = 0;
};

void bindChibi(v8::Local<v8::Context> context, v8::Local<v8::Object> chibi);
