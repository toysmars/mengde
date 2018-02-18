#ifndef DEPLOY_VIEW_H_
#define DEPLOY_VIEW_H_

#include "gui/uifw/callback_view.h"
#include "gui/uifw/composite_view.h"
#include "i_equipment_set_setter.h"

#include "common.h"

namespace mengde {
namespace core {

class Hero;
class Assets;
class IDeployHelper;

}  // namespace core
}  // namespace mengde

namespace mengde {
namespace gui {
namespace app {

class EquipmentSetView;
class EquipmentSelectView;
class UnitOverView;
class UnitView;

class HeroModelView : public CallbackView {
 public:
  HeroModelView(const Rect&, const core::Hero*, core::IDeployHelper*);
  void UpdateViews();
  void SetDeployNo(uint32_t no) { deploy_no_ = no; }
  bool IsSelected() { return deploy_no_ != 0; }

 private:
  const core::Hero* hero_;
  uint32_t          deploy_no_;
  bool              required_unselectable_;
  TextView*         tv_no_;
};

class HeroModelListView : public CompositeView {
 public:
  HeroModelListView(const Rect&, const vector<const core::Hero*>&, core::IDeployHelper*, UnitOverView*,
                    IEquipmentSetSetter*, EquipmentSelectView*);
};

// DeployView is a UI view for deploying heroes

class DeployView : public CompositeView {
 public:
  DeployView(const Rect&, core::Assets*, core::IDeployHelper*);

 private:
  UnitOverView*        unit_over_view_;
  EquipmentSetView*    equipment_set_view_;
  EquipmentSelectView* equipment_select_view_;
};

}  // namespace app
}  // namespace gui
}  // namespace mengde

#endif  // DEPLOY_VIEW_H_
