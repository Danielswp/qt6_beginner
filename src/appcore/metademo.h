#pragma once

// 学习用的实验函数集合，不参与产品逻辑。
// 每个函数对应一个知识点，方便单独回看和单独调用。

namespace SWP_DEMO_META{
void demoMetaObject();        // QMetaObject：className / superClass / inherits / metaType
void demoProperty();          // Q_PROPERTY：setProperty / property / NOTIFY
void demoInvoke();            // Q_INVOKABLE / slots：invokeMethod 三种调法
void runAllDemos();           // 一次性跑完（默认入口）
}
