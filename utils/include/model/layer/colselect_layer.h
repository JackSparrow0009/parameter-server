#ifndef UTILS_INCLUDE_MODEL_LAYER_COLSELECT_LAYER_H_
#define UTILS_INCLUDE_MODEL_LAYER_COLSELECT_LAYER_H_

#include <memory>
#include <Eigen>
#include "toolkit/config.h"
#include "model/data/matrix_output.h"
#include "model/layer/common/layer.h"

namespace ps {
namespace model {

class ColSelectLayer : public Layer {
 public:
  void load_config(ps::toolkit::Config conf);

  std::shared_ptr<MatrixOutput>& input() {
    return input_;
  }

  std::shared_ptr<MatrixOutput>& output() {
    return output_;
  }

  std::vector<int> & range(){
    return range_;
  }

  void initialize() override;
  void feed_forward() override;
  void back_propagate() override;

 private:
  std::shared_ptr<MatrixOutput> input_;
  std::shared_ptr<MatrixOutput> output_ = std::make_shared<MatrixOutput>();
  std::vector<int> range_;
};

} // namespace model
} // namespace ps

#endif // UTILS_INCLUDE_MODEL_LAYER_COLSELECT_LAYER_H_

