CUDA_VISIBLE_DEVICES=4,5 nohup sh scripts/train.sh -g 2 -d scannet -c intersemseg-spunet-mask3d-15 -n mask3d-25 > /dev/null 2>&1 &

CUDA_VISIBLE_DEVICES=0 nohup python -u test.py >/dev/null 2>&1 &

CUDA_VISIBLE_DEVICES=6,7,8 nohup sh scripts/train.sh -g 3 -d scannet -c intersemseg-spunet-mask3d-16 -w /data/shared_workspace/yuzijian/ws/iseg3d/exp/scannet/mask3d-14/model/model_best.pth -n mask3d-16 > /dev/null 2>&1 &

CUDA_VISIBLE_DEVICES=1,4,6,7 nohup sh scripts/train.sh -g 4 -d scannet -c intersemseg-spunet-mask3d-15 -w /data/shared_workspace/yuzijian/ws/iseg3d/exp/scannet/mask3d-25/model/model_best.pth -n mask3d-16 > /dev/null 2>&1 &

<!-- TODO 可学习的背景查询, 用于zero-shot分割背景前景 -->