---
name: linux-kernel-style
description: |
  本仓库的注释 skill。写、改、审 c_ocpp 与 qt_cp 的注释时使用。
  蒸馏自 Linux 内核 Documentation/process/coding-style.rst 的注释规则，
  上游是 happydog-intj/luban-skill 的 skills/linux-kernel.skill
  （该仓库是带 C 注释规范的 skill 仓库里 star 最多的一个）。
  触发词：「注释」「补注释」「kernel style」「像内核一样写 C」。
---

# 本仓库注释规范

写 `c_ocpp` 和 `qt_cp` 时按这四条，块注释仍用 `/* */`，对外函数用 `/** */`。Qt 的类名和 4 空格缩进保持 Qt 习惯。

1. 内部函数（`static`、仅本文件使用）用一行到三行的短注释，说明它负责什么。
2. 头文件里声明、给别的文件调用的函数要写详细注释：做什么、参数、返回值、调用约束。
3. 每个函数定义上方都要有注释，不能只在文件头写一段。
4. 分支、资源释放、协议状态这种关键片段也要有注释，说明为什么这样写。

上游全文来自 https://github.com/happydog-intj/luban-skill/tree/master/skills/linux-kernel.skill （仓库约 28 stars）。专门名叫 comment-skill 的仓库当时最高只有 1 star，而且不针对 C。

## 注释哲学

**核心原则：解释「为什么」，不解释「是什么」**

```c
/* 好注释：解释为什么这么做，而不是代码在做什么 */
/*
 * We need to disable interrupts here because the DMA controller
 * may fire an IRQ between the status check and the actual transfer,
 * causing a race condition on SMP systems.
 */
spin_lock_irqsave(&dev->lock, flags);

/* 废话注释：不要写 */
/* increment i by 1 */
i++;
```

**注释格式：**

- 块注释用 `/* */`，对齐成矩形
- 单行解释用 `/* ... */`，不用 `//`
- 函数和结构体用 `/** */`（kernel-doc）

```c
/**
 * usb_alloc_urb - allocate a URB for a USB driver
 * @iso_packets: number of iso packets for this URB
 * @mem_flags: allocation flags
 *
 * Returns a pointer to the newly allocated URB, or NULL on failure.
 */
struct urb *usb_alloc_urb(int iso_packets, gfp_t mem_flags)
```

不给一眼能看懂的语句补注释。函数超过一屏才考虑拆，那是结构问题，不是注释问题。
