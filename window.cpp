#include <GL/glut.h>
// 太阳、地球和月亮
// 假设每个月都是30天
// 一年12个月，共是360天
static int day = 200; // day的变化：从0到359
void myDisplay(void)
{
	//glEnable(GL_DEPTH_TEST); //启动深度测试（这样后绘制的图形如果在已经存在的图形的前面，它会被遮住，而不是遮住别人
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清空颜色和深度缓冲
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75, 1, 10, 400000000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);

	// 绘制红色的“太阳”
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(69600000, 20, 20);  //绘制一个球体，半径为69600000,水平线数为20，竖直线数为20，即将球体分成400份
	// 绘制蓝色的“地球”
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(day / 360.0 * 360.0, 0.0f, 0.0f, -1.0f); //绕z轴旋转的角度
	glTranslatef(150000000, 0.0f, 0.0f); //沿着x方向平移：150000000
	glutSolidSphere(15945000, 20, 20);
	// 绘制黄色的“月亮”
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(day / 30.0 * 360.0 - day / 360.0 * 360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(38000000, 0.0f, 0.0f);
	glutSolidSphere(4345000, 20, 20);

	glFlush(); //刷新：数据先放在缓冲区中，刷新后发送给驱动
	glutSwapBuffers();  //双缓冲区交换指针
}

void myIdle(void)
{
	/* 新的函数，在空闲时调用，作用是把日期往后移动一天并重新绘制，达到动画效果 */
	++day;
	if (day >= 360)
		day = 0;
	myDisplay();
    
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);//对GLUT进行初始化，这个函数必须在其它的GLUT使用之前调用一次
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //设置显示方式
	glutInitWindowPosition(100, 100); //设置窗口位置
	glutInitWindowSize(400, 400);//窗口大小
	glutCreateWindow("动画"); //根据前面设置的信息创建窗口。参数将被作为窗口的标题。
	glutDisplayFunc(&myDisplay); //当需要画图时，请调用myDisplay函数
	glutIdleFunc(&myIdle);
    
	glutMainLoop(); //进行一个消息循环
	return 0;
}
