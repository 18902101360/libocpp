#!/usr/bin/env bash
# 主机一键：配置 + 编译 + ctest（含 Python CSMS 联调）。
# 用法（仓库根或本目录均可）：
#   ./c_ocpp/build_and_test.sh
#   ./c_ocpp/build_and_test.sh --clean
#   ./c_ocpp/build_and_test.sh -- -DPython3_EXECUTABLE=/usr/bin/python3
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD="${BUILD_DIR:-$ROOT/build}"
JOBS="${JOBS:-}"
CLEAN=0

usage() {
    cat <<EOF
usage: $(basename "$0") [options] [-- extra cmake args]

  --clean, -c           删除构建目录后重配
  --jobs N, -j N        并行编译数（默认 nproc，否则 4）
  --build-dir DIR       构建目录（默认 c_ocpp/build，或环境变量 BUILD_DIR）
  -h, --help            本说明

  -- 之后的参数传给 cmake 配置，例如：
     $0 -- -G Ninja -DCMAKE_C_COMPILER=gcc
EOF
}

while [[ $# -gt 0 ]]; do
    case "$1" in
        --clean|-c)
            CLEAN=1
            shift
            ;;
        --jobs|-j)
            JOBS="${2:?--jobs 需要数字}"
            shift 2
            ;;
        --build-dir)
            BUILD="${2:?--build-dir 需要路径}"
            shift 2
            ;;
        -h|--help)
            usage
            exit 0
            ;;
        --)
            shift
            break
            ;;
        *)
            echo "未知参数: $1（额外 cmake 参数请写在 -- 后面）" >&2
            usage >&2
            exit 2
            ;;
    esac
done

if [[ -z "$JOBS" ]]; then
    if command -v nproc >/dev/null 2>&1; then
        JOBS="$(nproc)"
    else
        JOBS=4
    fi
fi

for cmd in cmake ctest python3 cc; do
    if ! command -v "$cmd" >/dev/null 2>&1; then
        echo "缺少命令: $cmd" >&2
        echo "Debian/Ubuntu: sudo apt install -y build-essential cmake python3" >&2
        exit 1
    fi
done

if [[ "$CLEAN" -eq 1 ]]; then
    echo "==> 清除 $BUILD"
    rm -rf "$BUILD"
fi

echo "==> 配置  cmake -S $ROOT -B $BUILD $*"
cmake -S "$ROOT" -B "$BUILD" "$@"

echo "==> 编译  cmake --build $BUILD -j$JOBS"
cmake --build "$BUILD" -j"$JOBS"

echo "==> 测试  ctest --test-dir $BUILD --output-on-failure"
ctest --test-dir "$BUILD" --output-on-failure

echo "==> 完成"
