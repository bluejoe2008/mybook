#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QTextCodec>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
	QWidget * pWidget = new QWidget;
	QLabel label(pWidget);
	label.setText(QObject::tr("�Ҳ��룬�ҷ��ף��ҿ��֣�"));
	
	pWidget->show();
	return app.exec();
}
