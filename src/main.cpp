#include <shot_executor_UAL.h>

int main(int _argc, char **_argv) {
  ros::init(_argc, _argv, "shot_executor");
  ros::NodeHandle nh;
  ros::NodeHandle pnh("~");

  std::unique_ptr<ShotExecuter> shot_executor_interface;

  shot_executor_interface = std::make_unique<ShotExecuterUAL>(nh, pnh);

  ros::spin();
  return 0;
}
