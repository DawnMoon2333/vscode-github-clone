import matplotlib.pyplot as plt  # 绘图
import numpy as np

# 使用外部数据，内容为房屋的面积与价格
'''
文件格式如下：
1.000000	0.635975	4.093119
1.000000	0.552438	3.804358
1.000000	0.855922	4.456531
1.000000	0.083386	3.187049
1.000000	0.975802	4.506176
'''


# 定义读取数据函数

def get_raw_data(file_path):
    raw_data = np.loadtxt(file_path, skiprows=1)
    cols = raw_data.shape[1]
    return (raw_data, raw_data[:, :cols - 1], raw_data[:, cols - 1:])
    # 返回rawdata、rawdata除最后一列、rawdata最后一列


# 定义梯度计算函数
'''
计算给定模型参数 theta 对应的梯度（即损失函数相对于 theta 的偏导数），以便可以在梯度下降算法中更新 theta，逐步找到最优的参数
1/m * X^T * (X * theta - y)
X.dot(theta)：特征矩阵X与模型参数theta的矩阵乘法，即预测值
X.dot(theta) - y：预测值-实际值，即残差
X.T.dot(X.dot(theta) - y)：将X转置后与残差相乘，得到每个特征在所有样本上的误差总和，即损失函数对每个theta的偏导数
X.shape[0]：X的第一个维度中的元素数，即样本数
将结果除以样本数得到平均梯度
'''


def get_gradient(X, theta, y):
    return (1 / X.shape[0]) * X.T.dot(X.dot(theta) - y)


# 初始化theta

def init_theta(y_count):
    return np.ones(y_count).reshape(y_count, 1)
    # 创建一个长度为y_count的一维数组，填充为1
    # 然后将他转化为y_count行1列的矩阵，即列向量


# 定义梯度下降函数
'''
Jtheta = (X.dot(theta) - y).T.dot(X.dot(theta) - y)
计算Jtheta的过程：
X.dot(theta) - y：预测值与实际值之差，即残差
转置后再乘，即平方
Jtheta即为均方误差
'''


def gradient_descending(X, y, theta, alpha):
    # 输入值X，真实值y，权重theta，学习率alpha
    Jthetas = []  # 存储损失函数的变化趋势，验证是否正常进行梯度下降
    Jtheta = (X.dot(theta) - y).T.dot(X.dot(theta) - y)
    index = 0  # 记录训练步数
    gradient = get_gradient(X, theta, y)  # 计算梯度
    while not np.all(np.absolute(gradient) <= 1e-5):  # 循环计算直到梯度小于1e-5
        theta = theta - alpha * gradient  # 用学习率确定权重大小
        gradient = get_gradient(X, theta, y)  # 计算新梯度
        Jtheta = (X.dot(theta) - y).T.dot(X.dot(theta) - y)  # 计算损失函数
        if (index + 1) % 10 == 0:
            Jthetas.append((index, Jtheta[0]))  # 每10次存储一次损失函数值
        index += 1
    return theta, Jthetas


# 绘图展示Jtheta

def show_Jtheta(diff_value):
    x = []
    y = []
    for (index, sum) in diff_value:
        x.append(index)
        y.append(sum)
    plt.plot(x, y, color='b')
    plt.xlabel("steps")
    plt.ylabel("loss")
    plt.title("loss function")
    plt.show()


def show_fitting(theta, training_set):
    # theta包含训练得到的截距和斜率
    x, y = training_set[:, 1], training_set[:, 2]
    z = theta[0] + theta[1] * x  # 计算预测值
    # 绘制散点图
    plt.scatter(x, y, color='b', marker='x', label='sample data')
    # 绘制回归曲线
    plt.plot(x, z, color='r', label='regression curve')
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title('linear regression curve')
    plt.legend()
    plt.show()


def main():
    file_path = "lr2_data.txt"
    raw_data, raw_data_x, raw_data_y = get_raw_data(file_path)
    x_count, y_count = raw_data_x.shape
    alpha = 0.01  # 学习步长
    theta = init_theta(y_count)
    final_theta, Jthetas = gradient_descending(raw_data_x, raw_data_y, theta, alpha)
    print("拟合得到的截距=", theta[0][0], "，斜率=", theta[1][0])
    show_Jtheta(Jthetas)
    show_fitting(final_theta, raw_data)


if __name__ == "__main__":
    main()
